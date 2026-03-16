// symtab.c
#include "common.h"
#include <string.h>

// 全局符号表
SymbolTable symbol_table;
CompileTiming compile_timing;

// 哈希函数
static int hash(const char* name) {
    unsigned int hash_value = 0;
    while (*name) {
        hash_value = (hash_value << 5) + *name++;
    }
    return hash_value % 100;
}

// 初始化符号表
void init_symbol_table() {
    for (int i = 0; i < 100; i++) {
        symbol_table.buckets[i] = NULL;
    }
    symbol_table.scope_level = 0;
    symbol_table.next_address = 0;
    symbol_table.count = 0;
}

// 进入新的作用域
void enter_scope() {
    symbol_table.scope_level++;
}

// 退出作用域（删除当前作用域的所有符号）
void exit_scope() {
    for (int i = 0; i < 100; i++) {
        SymbolEntry* prev = NULL;
        SymbolEntry* curr = symbol_table.buckets[i];
        
        while (curr != NULL) {
            if (curr->scope_level == symbol_table.scope_level) {
                // 删除当前作用域的符号
                if (prev == NULL) {
                    symbol_table.buckets[i] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                SymbolEntry* to_free = curr;
                curr = curr->next;
                free(to_free);
                symbol_table.count--;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    symbol_table.scope_level--;
}

// 插入新符号
SymbolEntry* insert_symbol(const char* name, SymbolType sym_type, DataType data_type, int line) {
    // 检查当前作用域是否已存在同名符号
    SymbolEntry* existing = lookup_current_scope(name);
    if (existing != NULL) {
        fprintf(stderr, "语义错误：变量 '%s' 在第 %d 行重复声明\n", name, line);
        return NULL;
    }
    
    int index = hash(name);
    SymbolEntry* new_entry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
    
    strcpy(new_entry->name, name);
    new_entry->sym_type = sym_type;
    new_entry->data_type = data_type;
    new_entry->is_initialized = 0;
    new_entry->scope_level = symbol_table.scope_level;
    new_entry->memory_address = symbol_table.next_address++;
    new_entry->line_declared = line;
    new_entry->next = symbol_table.buckets[index];
    
    symbol_table.buckets[index] = new_entry;
    symbol_table.count++;
    
    return new_entry;
}

// 查找符号（在所有作用域中）
SymbolEntry* lookup_symbol(const char* name) {
    int index = hash(name);
    SymbolEntry* curr = symbol_table.buckets[index];
    
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// 查找符号（仅在当前作用域）
SymbolEntry* lookup_current_scope(const char* name) {
    int index = hash(name);
    SymbolEntry* curr = symbol_table.buckets[index];
    
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0 && curr->scope_level == symbol_table.scope_level) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// 在 symtab.c 中修改 print_symbol_table 函数
void print_symbol_table() {
    printf("\n======= 符号表（%d个符号） =======\n", symbol_table.count);
    
    // 使用统一的格式化字符串
    const char* format = "%-8s  %-6s  %-8s  %-6s  %-6s  %-6s  %-6s\n";
    
    // 表头
    printf(format, "名称", "类型", "数据类型", "初始化", "作用域", "地址", "声明行");
    
    // 分隔线 - 根据格式手动计算长度
    printf("------------------------------------------------------------\n");
    
    // 数据行
    for (int i = 0; i < 100; i++) {
        SymbolEntry* curr = symbol_table.buckets[i];
        while (curr != NULL) {
            const char* type_str = "";
            switch (curr->sym_type) {
                case SYM_VARIABLE: type_str = "变量"; break;
                case SYM_FUNCTION: type_str = "函数"; break;
                case SYM_TYPE: type_str = "类型"; break;
                case SYM_CONSTANT: type_str = "常量"; break;
            }
            
            const char* data_type_str = "";
            switch (curr->data_type) {
                case TYPE_INT: data_type_str = "int"; break;
                case TYPE_FLOAT: data_type_str = "float"; break;
                case TYPE_BOOL: data_type_str = "bool"; break;
                case TYPE_VOID: data_type_str = "void"; break;
                case TYPE_UNKNOWN: data_type_str = "unknown"; break;
            }
            
            const char* init_str = curr->is_initialized ? "是" : "否";
            
            // 将整数转换为字符串
            char scope_str[20], addr_str[20], line_str[20];
            sprintf(scope_str, "%d", curr->scope_level);
            sprintf(addr_str, "%d", curr->memory_address);
            sprintf(line_str, "%d", curr->line_declared);
            
            // 使用统一的格式打印
            printf(format, 
                   curr->name,
                   type_str,
                   data_type_str,
                   init_str,
                   scope_str,
                   addr_str,
                   line_str);
            
            curr = curr->next;
        }
    }
    printf("======= 符号表结束 =======\n");
}


/*
// 准备打印符号表
// 辅助函数：计算字符串的显示宽度（中文算2个宽度，英文算1个）
static int display_width(const char* str) {
    int width = 0;
    while (*str) {
        // 判断是否为中文字符（UTF-8中文字符的第一个字节范围）
        if ((*str & 0xE0) == 0xC0) {
            width += 2;  // 中文字符显示宽度为2
            str += 2;    // 跳过UTF-8编码的两个字节
        } else {
            width += 1;  // 英文字符显示宽度为1
            str += 1;
        }
    }
    return width;
}

// 辅助函数：输出指定宽度的字符串，不足用空格补齐
static void print_aligned(const char* str, int width) {
    int str_width = display_width(str);
    printf("%s", str);
    
    // 补空格
    for (int i = str_width; i < width; i++) {
        printf(" ");
    }
}

// 打印符号表
void print_symbol_table() {
    printf("\n======= 符号表（%d个符号） =======\n", symbol_table.count);

    // 表头定义
    const char* headers[] = {"名称", "类型", "数据类型", "初始化", "作用域", "地址", "声明行"};
    const int widths[] = {10, 8, 10, 8, 8, 8, 8};  // 每列的显示宽度

    // 打印表头
    for (int i = 0; i < 7; i++) {
        print_aligned(headers[i], widths[i]);
        if (i < 6) printf(" ");
    }
    printf("\n");

    // 打印分隔线
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < widths[i]; j++) {
            printf("-");
        }
        if (i < 6) printf(" ");
    }
    printf("\n");

    // 打印数据行
    for (int i = 0; i < 100; i++) {
        SymbolEntry* curr = symbol_table.buckets[i];
        while (curr != NULL) {
            const char* type_str = "";
            switch (curr->sym_type) {
                case SYM_VARIABLE: type_str = "变量"; break;
                case SYM_FUNCTION: type_str = "函数"; break;
                case SYM_TYPE: type_str = "类型"; break;
                case SYM_CONSTANT: type_str = "常量"; break;
            }

            const char* data_type_str = "";
            switch (curr->data_type) {
                case TYPE_INT: data_type_str = "int"; break;
                case TYPE_FLOAT: data_type_str = "float"; break;
                case TYPE_BOOL: data_type_str = "bool"; break;
                case TYPE_VOID: data_type_str = "void"; break;
                case TYPE_UNKNOWN: data_type_str = "unknown"; break;
            }

            const char* init_str = curr->is_initialized ? "是" : "否";

            // 将整数转换为字符串
            char scope_str[20], addr_str[20], line_str[20];
            sprintf(scope_str, "%d", curr->scope_level);
            sprintf(addr_str, "%d", curr->memory_address);
            sprintf(line_str, "%d", curr->line_declared);

            // 打印每一列，对齐
            print_aligned(curr->name, widths[0]); printf(" ");
            print_aligned(type_str, widths[1]); printf(" ");
            print_aligned(data_type_str, widths[2]); printf(" ");
            print_aligned(init_str, widths[3]); printf(" ");
            print_aligned(scope_str, widths[4]); printf(" ");
            print_aligned(addr_str, widths[5]); printf(" ");
            print_aligned(line_str, widths[6]);

            printf("\n");

            curr = curr->next;
        }
    }
    printf("======= 符号表结束 =======\n");
}
*/
