// optimize.c - 修改后版本
#include "common.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 检查是否为数字
static int is_numeric(const char* str) {
    if (!str || !str[0]) return 0;
    for (int i = 0; str[i]; i++) {
        if (!isdigit((unsigned char)str[i]) && !(i == 0 && str[i] == '-')) 
            return 0;
    }
    return 1;
}

// 常量表结构
typedef struct {
    char var_name[32];  // 变量名
    char const_value[32]; // 常量值
    int is_valid;       // 是否有效
} ConstEntry;

static ConstEntry const_table[100];
static int const_count = 0;

// 查找变量是否在常量表中
static char* find_const_value(const char* var_name) {
    for (int i = 0; i < const_count; i++) {
        if (const_table[i].is_valid && strcmp(const_table[i].var_name, var_name) == 0) {
            return const_table[i].const_value;
        }
    }
    return NULL;
}

// 从常量表中移除变量
static void remove_from_const_table(const char* var_name) {
    for (int i = 0; i < const_count; i++) {
        if (strcmp(const_table[i].var_name, var_name) == 0) {
            const_table[i].is_valid = 0;
        }
    }
}

// 常量传播优化
static void constant_propagation() {
    printf("执行常量传播优化...\n");
    
    // 清空常量表
    const_count = 0;
    for (int i = 0; i < 100; i++) {
        const_table[i].is_valid = 0;
    }
    
    // 第一遍：收集所有明确的常量赋值
    for (int i = 0; i < quadCount; i++) {
        Quadruple* q = &quadruples[i];
        
        // 如果是常量赋值语句: = 3 _ b
        if (strcmp(q->op, "=") == 0 && is_numeric(q->arg1) && strcmp(q->arg2, "_") == 0) {
            // 检查是否已存在
            int found = -1;
            for (int j = 0; j < const_count; j++) {
                if (const_table[j].is_valid && strcmp(const_table[j].var_name, q->result) == 0) {
                    found = j;
                    break;
                }
            }
            
            if (found >= 0) {
                // 更新已有的常量值
                strcpy(const_table[found].const_value, q->arg1);
                printf("   更新常量: %s = %s\n", q->result, q->arg1);
            } else if (const_count < 100) {
                // 添加新的常量
                strcpy(const_table[const_count].var_name, q->result);
                strcpy(const_table[const_count].const_value, q->arg1);
                const_table[const_count].is_valid = 1;
                printf("   发现常量: %s = %s\n", q->result, q->arg1);
                const_count++;
            }
        }
        // 如果变量被重新赋值（非常量），则从常量表中移除
        else if (strcmp(q->op, "=") == 0 && strcmp(q->arg2, "_") == 0) {
            remove_from_const_table(q->result);
            printf("   变量 %s 被重新赋值，从常量表中移除\n", q->result);
        }
        // 如果是输入语句，变量值未知，从常量表中移除
        else if (strcmp(q->op, "IN") == 0) {
            remove_from_const_table(q->result);
            printf("   变量 %s 为输入值，从常量表中移除\n", q->result);
        }
    }
    
    // 第二遍：应用常量传播
    for (int i = 0; i < quadCount; i++) {
        Quadruple* q = &quadruples[i];
        
        // 检查操作数1是否可被常量替换
        if (!is_numeric(q->arg1) && strcmp(q->arg1, "_") != 0) {
            char* const_val = find_const_value(q->arg1);
            if (const_val) {
                printf("   传播: 将 %s 替换为 %s\n", q->arg1, const_val);
                strcpy(q->arg1, const_val);
            }
        }
        
        // 检查操作数2是否可被常量替换
        if (!is_numeric(q->arg2) && strcmp(q->arg2, "_") != 0) {
            char* const_val = find_const_value(q->arg2);
            if (const_val) {
                printf("   传播: 将 %s 替换为 %s\n", q->arg2, const_val);
                strcpy(q->arg2, const_val);
            }
        }
    }
}

// 改进的常量折叠（能利用常量传播后的结果）
static void constant_folding() {
    printf("执行常量折叠优化...\n");
    int folded_count = 0;
    
    for (int i = 0; i < quadCount; i++) {
        Quadruple* q = &quadruples[i];
        
        // 检查两个操作数是否都是数字（经过常量传播后可能都是数字了）
        int can_fold = 0;
        int val1 = 0, val2 = 0;
        
        if (is_numeric(q->arg1)) {
            val1 = atoi(q->arg1);
            if (strcmp(q->arg2, "_") == 0) {
                // 单操作数情况：赋值或一元运算
                can_fold = 1;
            } else if (is_numeric(q->arg2)) {
                // 双操作数都是数字
                val2 = atoi(q->arg2);
                can_fold = 1;
            }
        }
        
        if (can_fold) {
            // 根据操作符执行折叠
            int result = 0;
            int should_fold = 1;
            
            if (strcmp(q->op, "+") == 0) {
                result = val1 + val2;
            } else if (strcmp(q->op, "-") == 0) {
                result = val1 - val2;
            } else if (strcmp(q->op, "*") == 0) {
                result = val1 * val2;
            } else if (strcmp(q->op, "/") == 0) {
                if (val2 != 0) {
                    result = val1 / val2;
                } else {
                    should_fold = 0; // 除零，不折叠
                }
            } else if (strcmp(q->op, ">") == 0) {
                result = (val1 > val2) ? 1 : 0;
            } else if (strcmp(q->op, "<") == 0) {
                result = (val1 < val2) ? 1 : 0;
            } else if (strcmp(q->op, ">=") == 0) {
                result = (val1 >= val2) ? 1 : 0;
            } else if (strcmp(q->op, "<=") == 0) {
                result = (val1 <= val2) ? 1 : 0;
            } else if (strcmp(q->op, "==") == 0) {
                result = (val1 == val2) ? 1 : 0;
            } else if (strcmp(q->op, "!=") == 0) {
                result = (val1 != val2) ? 1 : 0;
            } else if (strcmp(q->op, "=") == 0) {
                // 赋值语句已经是常量，不需要折叠
                should_fold = 0;
            } else {
                should_fold = 0; // 不支持的操作符
            }
            
            if (should_fold) {
                // 替换为常量赋值
                char old_op[32], old_arg1[32], old_arg2[32];
                strcpy(old_op, q->op);
                strcpy(old_arg1, q->arg1);
                strcpy(old_arg2, q->arg2);
                
                strcpy(q->op, "=");
                sprintf(q->arg1, "%d", result);
                strcpy(q->arg2, "_");
                
                printf("   折叠: %s %s %s %s -> = %d _ %s\n", 
                       old_op, old_arg1, old_arg2, q->result, result, q->result);
                folded_count++;
            }
        }
    }
    
    if (folded_count == 0) {
        printf("   没有找到可折叠的常量表达式\n");
    }
}

// 主优化函数 - 顺序执行优化步骤
void optimize_quadruples(void) {
    printf("\n=== 中间代码优化 ===\n");
    printf("开始优化四元式...\n");
    
    // 优化步骤1: 常量传播（将变量替换为常量值）
    constant_propagation();
    
    // 优化步骤2: 常量折叠（计算常量表达式）
    constant_folding();
    
    printf("优化完成。\n");
}
