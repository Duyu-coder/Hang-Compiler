#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 语法树节点类型枚举
typedef enum 
{
    NODE_PROGRAM,       // 程序节点
    NODE_DECLARATION,   // 声明节点
    NODE_ASSIGNMENT,    // 赋值节点
    NODE_INPUT,         // 输入节点
    NODE_OUTPUT,        // 输出节点
    NODE_WHEN,          // when节点
    NODE_EXPRESSION,    // 表达式节点
    NODE_IDENTIFIER,    // 标识符节点
    NODE_CONSTANT,      // 常量节点
    NODE_OPERATOR,      // 运算符节点
    NODE_TYPE,          // 类型节点
    NODE_STATEMENT_LIST // 语句列表节点
} NodeType;

// 简化的语法树节点结构体
typedef struct ASTNode 
{
    NodeType type;              // 节点类型
    char* value;                // 节点值
    
    struct ASTNode* first_child;   // 第一个子节点
    struct ASTNode* next_sibling;  // 下一个兄弟节点
    
} ASTNode;

// 函数声明
ASTNode* createNode(NodeType type, const char* value);
void addChild(ASTNode* parent, ASTNode* child);
void addSibling(ASTNode* node, ASTNode* sibling);
void printAST(ASTNode* node, int depth);
void freeAST(ASTNode* node);

#endif
