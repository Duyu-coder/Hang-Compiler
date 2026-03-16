// optimize.h
#ifndef OPTIMIZE_H
#define OPTIMIZE_H

#include "common.h"

// 优化类型
typedef enum {
    OPT_CONSTANT_FOLDING,      // 常量折叠
    OPT_CONSTANT_PROPAGATION,  // 常量传播
    OPT_CSE,                   // 公共子表达式消除
    OPT_DEAD_CODE,             // 死代码消除
} OptimizationType;

// 优化函数声明
void optimize_quadruples();
void constant_folding();
void constant_propagation();
void common_subexpression_elimination();
void dead_code_elimination();
void print_optimization_report();

#endif
