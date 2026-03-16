// semantic.c
#include "common.h"
#include <string.h>

// 当前处理的AST节点行号
static int current_line = 1;

// 错误计数
static int semantic_error_count = 0;

// 将字符串转换为数据类型
DataType string_to_type(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return TYPE_INT;
    if (strcmp(type_str, "float") == 0) return TYPE_FLOAT;
    if (strcmp(type_str, "bool") == 0) return TYPE_BOOL;
    return TYPE_UNKNOWN;
}

// 语义分析主函数
void semantic_check(ASTNode* node) {
    if (node == NULL) return;
    
    // 更新当前行号（假设AST节点有line_number字段）
    // 如果没有，我们可以使用其他方式获取行号
    // 这里我们先假设节点有行号信息
    
    switch (node->type) {
        case NODE_PROGRAM:
            // 全局作用域，直接处理子节点
            for (ASTNode* child = node->first_child; child != NULL; child = child->next_sibling) {
                semantic_check(child);
            }
            break;
            
        case NODE_DECLARATION: {
            // 变量声明语义检查
            ASTNode* type_node = node->first_child;
            ASTNode* id_node = type_node ? type_node->next_sibling : NULL;
            
            if (type_node && id_node) {
                DataType var_type = string_to_type(type_node->value);
                
                // 处理多个标识符的情况（如 int a, b, c;）
                ASTNode* current_id = id_node;
                while (current_id != NULL && current_id->type == NODE_IDENTIFIER) {
                    // 插入符号表，使用current_line作为行号
                    // 注意：如果有更精确的行号信息，应该使用节点的行号字段
                    SymbolEntry* entry = insert_symbol(
                        current_id->value, 
                        SYM_VARIABLE, 
                        var_type, 
                        current_line  // 使用当前行号，而不是0
                    );
                    
                    // 检查是否有初始化表达式
                    if (current_id->first_child != NULL) {
                        // 变量初始化
                        if (entry != NULL) {
                            entry->is_initialized = 1;
                        }
                        // 检查初始化表达式
                        semantic_check(current_id->first_child);
                    }
                    
                    current_id = current_id->next_sibling;
                }
            }
            break;
        }
            
        case NODE_ASSIGNMENT: {
            // 赋值语句语义检查
            ASTNode* left = node->first_child;
            ASTNode* right = left ? left->next_sibling : NULL;
            
            if (left && left->type == NODE_IDENTIFIER) {
                // 检查左值是否已声明
                SymbolEntry* entry = lookup_symbol(left->value);
                if (entry == NULL) {
                    fprintf(stderr, "语义错误（第%d行）: 变量 '%s' 在使用前未声明\n", 
                           current_line, left->value);
                    semantic_error_count++;
                } else {
                    // 标记为已初始化
                    entry->is_initialized = 1;
                }
            }
            
            // 检查右值表达式
            if (right) {
                semantic_check(right);
            }
            break;
        }
            
        case NODE_INPUT: {
            // 输入语句语义检查
            ASTNode* id_node = node->first_child;
            if (id_node && id_node->type == NODE_IDENTIFIER) {
                SymbolEntry* entry = lookup_symbol(id_node->value);
                if (entry == NULL) {
                    fprintf(stderr, "语义错误（第%d行）: 变量 '%s' 在使用前未声明\n", 
                           current_line, id_node->value);
                    semantic_error_count++;
                } else {
                    // 输入后变量被视为已初始化
                    entry->is_initialized = 1;
                }
            }
            break;
        }
            
        case NODE_OUTPUT: {
            // 输出语句语义检查
            ASTNode* expr_node = node->first_child;
            if (expr_node) {
                semantic_check(expr_node);
            }
            break;
        }
            
        case NODE_IDENTIFIER: {
            // 标识符语义检查（非声明中的使用）
            // 注意：在声明中的标识符不会走到这里
            SymbolEntry* entry = lookup_symbol(node->value);
            if (entry == NULL) {
                fprintf(stderr, "语义错误（第%d行）: 变量 '%s' 在使用前未声明\n", 
                       current_line, node->value);
                semantic_error_count++;
            } else if (!entry->is_initialized) {
                fprintf(stderr, "警告（第%d行）: 变量 '%s' 在使用前可能未初始化\n", 
                       current_line, node->value);
                // 警告不计入错误计数
            }
            break;
        }
            
        case NODE_WHEN: {
            // 条件语句语义检查
            ASTNode* cond_node = node->first_child;
            ASTNode* body_node = cond_node ? cond_node->next_sibling : NULL;
            
            if (cond_node) {
                semantic_check(cond_node);
            }
            
            if (body_node) {
                // 进入条件语句块作用域
                enter_scope();
                semantic_check(body_node);
                exit_scope();
            }
            break;
        }
            
        case NODE_CONSTANT:
        case NODE_TYPE:
            // 这些节点不需要特殊处理
            break;
            
        case NODE_OPERATOR:
            // 检查操作符的子节点
            for (ASTNode* child = node->first_child; child != NULL; child = child->next_sibling) {
                semantic_check(child);
            }
            break;
            
        default:
            // 递归检查所有子节点
            for (ASTNode* child = node->first_child; child != NULL; child = child->next_sibling) {
                semantic_check(child);
            }
            break;
    }
    
    // 递归检查兄弟节点
    if (node->next_sibling) {
        semantic_check(node->next_sibling);
    }
}

// 获取语义错误数量
int get_semantic_error_count() {
    return semantic_error_count;
}
