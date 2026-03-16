#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将节点类型转换为字符串
const char* nodeTypeToString(NodeType type) {
    switch(type) {
        case NODE_PROGRAM: return "PROGRAM";
        case NODE_DECLARATION: return "DECLARATION";
        case NODE_ASSIGNMENT: return "ASSIGNMENT";
        case NODE_INPUT: return "INPUT";
        case NODE_OUTPUT: return "OUTPUT";
        case NODE_WHEN: return "WHEN";
        case NODE_EXPRESSION: return "EXPRESSION";
        case NODE_IDENTIFIER: return "IDENTIFIER";
        case NODE_CONSTANT: return "CONSTANT";
        case NODE_OPERATOR: return "OPERATOR";
        case NODE_TYPE: return "TYPE";
        case NODE_STATEMENT_LIST: return "STATEMENT_LIST";
        default: return "UNKNOWN";
    }
}

// 递归打印AST的辅助函数
void printASTRecursive(ASTNode* node, int depth, int isLast[], int currentDepth) {
    if (node == NULL) return;
    
    // 打印当前节点的缩进
    for (int i = 0; i < currentDepth; i++) {
        if (i == currentDepth - 1) {
            printf(isLast[i] ? " `--->" : " |--->");
        } else {
            printf(isLast[i] ? "     " : " |   ");
        }
    }
    
    // 打印节点信息
    if (node->value && strlen(node->value) > 0) {
        printf("%s [%s]\n", nodeTypeToString(node->type), node->value);
    } else {
        printf("%s\n", nodeTypeToString(node->type));
    }
    
    // 递归打印子节点
    ASTNode* child = node->first_child;
    int childCount = 0;
    
    // 计算子节点数量
    ASTNode* temp = child;
    while (temp != NULL) {
        childCount++;
        temp = temp->next_sibling;
    }
    
    // 更新深度数组
    if (currentDepth >= 0) {
        isLast[currentDepth] = 0; // 默认不是最后一个
    }
    
    // 递归打印每个子节点
    int index = 0;
    while (child != NULL) {
        // 标记是否是最后一个子节点
        if (currentDepth >= 0) {
            isLast[currentDepth] = (index == childCount - 1) ? 1 : 0;
        }
        
        // 递归打印子节点
        printASTRecursive(child, depth + 1, isLast, currentDepth + 1);
        
        child = child->next_sibling;
        index++;
    }
    
    // 恢复深度数组
    if (currentDepth >= 0) {
        isLast[currentDepth] = 0;
    }
}

// 打印抽象语法树的主函数
void printAST(ASTNode* node, int depth) {
    if (node == NULL) {
        printf("语法树为空\n");
        return;
    }
    
    // 创建数组来跟踪每个深度是否是最后一个节点
    int isLast[100] = {0}; // 假设深度不会超过100
    
    // 根节点特殊处理
    if (node->value && strlen(node->value) > 0) {
        printf("%s [%s]\n", nodeTypeToString(node->type), node->value);
    } else {
        printf("%s\n", nodeTypeToString(node->type));
    }
    
    // 递归打印子节点
    ASTNode* child = node->first_child;
    int childCount = 0;
    
    // 计算子节点数量
    ASTNode* temp = child;
    while (temp != NULL) {
        childCount++;
        temp = temp->next_sibling;
    }
    
    // 打印每个子节点
    int index = 0;
    while (child != NULL) {
        isLast[0] = (index == childCount - 1) ? 1 : 0;
        printASTRecursive(child, 1, isLast, 1);
        child = child->next_sibling;
        index++;
    }
}

// 创建AST节点
ASTNode* createNode(NodeType type, const char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (node == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(1);
    }
    
    node->type = type;
    if (value != NULL) {
        node->value = strdup(value);
    } else {
        node->value = NULL;
    }
    
    node->first_child = NULL;
    node->next_sibling = NULL;
    
    return node;
}

// 添加子节点
void addChild(ASTNode* parent, ASTNode* child) {
    if (parent == NULL || child == NULL) return;
    
    if (parent->first_child == NULL) {
        parent->first_child = child;
    } else {
        ASTNode* lastChild = parent->first_child;
        while (lastChild->next_sibling != NULL) {
            lastChild = lastChild->next_sibling;
        }
        lastChild->next_sibling = child;
    }
}

// 添加兄弟节点
void addSibling(ASTNode* node, ASTNode* sibling) {
    if (node == NULL || sibling == NULL) return;
    
    ASTNode* temp = node;
    while (temp->next_sibling != NULL) {
        temp = temp->next_sibling;
    }
    temp->next_sibling = sibling;
}

// 释放AST内存
void freeAST(ASTNode* node) {
    if (node == NULL) return;
    
    // 递归释放子节点
    freeAST(node->first_child);
    
    // 递归释放兄弟节点
    freeAST(node->next_sibling);
    
    // 释放节点值
    if (node->value != NULL) {
        free(node->value);
    }
    
    // 释放节点本身
    free(node);
}
