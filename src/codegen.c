// codegen.c - 修改后版本
#include "common.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 四元式数组和计数器
Quadruple quadruples[1000];
int quadCount = 0;
int tempVarCount = 0;
int labelCount = 0;

// 辅助函数：检查字符串是否为纯数字常量
int isStringNumeric(const char* str) {
    if (!str || !str[0]) return 0;
    
    // 允许负号开头
    int start = 0;
    if (str[0] == '-') start = 1;
    
    // 检查剩余字符是否都是数字
    for (int i = start; str[i]; i++) {
        if (!isdigit((unsigned char)str[i])) return 0;
    }
    return 1;
}

// 生成新的临时变量名
char* newTemp() {
    // 使用动态分配，避免静态缓冲区被覆盖
    char* tempName = (char*)malloc(20);
    if (tempName) {
        sprintf(tempName, "t%d", tempVarCount++);
    }
    return tempName;
}

// 生成新的标签名
char* newLabel() {
    static char labelName[20];
    sprintf(labelName, "L%d", labelCount++);
    return labelName;
}

// 添加四元式 - 修正版本
void addQuadruple(const char* op, const char* arg1, const char* arg2, const char* result) {
    if (quadCount < 1000) {
        strcpy(quadruples[quadCount].op, op);
        strcpy(quadruples[quadCount].arg1, arg1);
        strcpy(quadruples[quadCount].arg2, arg2);  // 修正这一行
        strcpy(quadruples[quadCount].result, result);
        quadCount++;
    }
}

// 打印四元式表
void printQuadruples() {
    printf("\n======= 四元式序列 =======\n");
    printf("序号\t操作符\t操作数1\t操作数2\t结果\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < quadCount; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n", 
               i, 
               quadruples[i].op,
               quadruples[i].arg1,
               quadruples[i].arg2,
               quadruples[i].result);
    }
    printf("======= 四元式结束 =======\n");
}

// 生成表达式的四元式，返回结果变量名
char* generateExpression(ASTNode* node) {
    if (!node) return NULL;

    switch (node->type) {
        case NODE_IDENTIFIER:
        case NODE_CONSTANT:
            return strdup(node->value);  // 使用 strdup 复制字符串

        case NODE_OPERATOR:
            if (node->first_child && node->first_child->next_sibling) {
                ASTNode* left = node->first_child;
                ASTNode* right = node->first_child->next_sibling;

                char* left_result = generateExpression(left);
                char* right_result = generateExpression(right);
                
                if (left_result && right_result) {
                    // !!! 关键优化：检查两个操作数是否都是数字常量 !!!
                    if (isStringNumeric(left_result) && isStringNumeric(right_result)) {
                        // 纯常量运算，直接计算！
                        int leftVal = atoi(left_result);
                        int rightVal = atoi(right_result);
                        int resultVal;
                        
                        // 根据运算符计算
                        if (strcmp(node->value, "+") == 0) {
                            resultVal = leftVal + rightVal;
                        } else if (strcmp(node->value, "-") == 0) {
                            resultVal = leftVal - rightVal;
                        } else if (strcmp(node->value, "*") == 0) {
                            resultVal = leftVal * rightVal;
                        } else if (strcmp(node->value, "/") == 0) {
                            if (rightVal != 0) {
                                resultVal = leftVal / rightVal;
                            } else {
                                // 除零错误，按常规处理
                                goto normal_generation;
                            }
                        } else {
                            // 其他运算符，按常规处理
                            goto normal_generation;
                        }
                        
                        // 生成一个直接赋值的四元式
                        char* result_temp = newTemp();
                        char resultStr[32];
                        sprintf(resultStr, "%d", resultVal);
                        addQuadruple("=", resultStr, "_", result_temp);
                        
                        // 调试输出
                        printf("代码生成阶段折叠: %s %s %s -> %d\n", 
                               node->value, left_result, right_result, resultVal);
                        
                        // 释放子表达式内存
                        free(left_result);
                        free(right_result);
                        
                        return result_temp;
                    }
                    
normal_generation:
                    // 非常量情况，正常生成运算四元式
                    char* result_temp = newTemp();
                    addQuadruple(node->value, left_result, right_result, result_temp);
                    
                    // 释放子表达式内存
                    free(left_result);
                    free(right_result);
                    
                    return result_temp;
                }
                
                // 错误处理：释放已分配的内存
                if (left_result) free(left_result);
                if (right_result) free(right_result);
            }
            break;

        default:
            // 对于其他类型的节点，不应该出现在表达式中
            break;
    }

    return NULL;
}

// 生成代码的主函数
void generateCode(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_PROGRAM:
        case NODE_STATEMENT_LIST:
            if (node->first_child) {
                ASTNode* child = node->first_child;
                while (child) {
                    generateCode(child);
                    child = child->next_sibling;
                }
            }
            break;

        case NODE_DECLARATION:
            // 现在声明不生成四元式，但如果是带初始化的声明，仍然生成赋值
            if (strcmp(node->value, "decl_init") == 0) {
                // 带初始化的声明: int c = 3;
                ASTNode* type_node = node->first_child;
                ASTNode* id_node = type_node ? type_node->next_sibling : NULL;
                ASTNode* init_node = id_node ? id_node->next_sibling : NULL;
                
                if (id_node && init_node && id_node->type == NODE_IDENTIFIER) {
                    // 为带初始化的声明生成赋值四元式
                    char* init_result = generateExpression(init_node);
                    if (init_result) {
                        addQuadruple("=", init_result, "_", id_node->value);
                        free(init_result);
                    }
                }
            }
            // 普通声明（int a, b;）不生成任何四元式
            break;

        case NODE_ASSIGNMENT:
            if (node->first_child && node->first_child->next_sibling) {
                ASTNode* left = node->first_child;
                ASTNode* right = node->first_child->next_sibling;
                
                char* right_result = generateExpression(right);
                if (right_result) {
                    addQuadruple("=", right_result, "_", left->value);
                    free(right_result);  // 释放内存
                }
            }
            break;

        case NODE_INPUT:
            if (node->first_child) {
                addQuadruple("IN", "_", "_", node->first_child->value);
            }
            break;

        case NODE_OUTPUT:
            if (node->first_child) {
                char* expr_result = generateExpression(node->first_child);
                if (expr_result) {
                    addQuadruple("OUT", expr_result, "_", "_");
                    free(expr_result);  // 释放内存
                }
            }
            break;

        case NODE_WHEN:
            if (node->first_child && node->first_child->next_sibling) {
                ASTNode* condition_node = node->first_child;
                ASTNode* body_node = node->first_child->next_sibling;

                char* cond_result = generateExpression(condition_node);

                if (cond_result) {
                    char* false_label = newLabel();
                    addQuadruple("JZ", cond_result, "_", false_label);
                    generateCode(body_node);
                    addQuadruple("LABEL", false_label, "_", "_");
                    free(cond_result);  // 释放内存
                }
            }
            break;

        default:
            if (node->first_child) {
                generateCode(node->first_child);
            }
            break;
    }
}

// 生成四元式的入口函数
void generateQuadruples(ASTNode* node) {
    printf("\n开始生成四元式...\n");
    printf("=================================\n");
    quadCount = 0;
    tempVarCount = 0;
    labelCount = 0;
    generateCode(node);
    printf("=================================\n");
    printf("四元式生成完成，共生成 %d 个四元式\n", quadCount);
}
