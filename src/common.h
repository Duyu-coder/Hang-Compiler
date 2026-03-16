// common.h
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ast.h"

// 符号类型枚举
typedef enum {
    SYM_VARIABLE,     // 变量
    SYM_FUNCTION,     // 函数
    SYM_TYPE,         // 类型
    SYM_CONSTANT      // 常量
} SymbolType;

// 数据类型枚举
typedef enum {
    TYPE_INT,         // 整数类型
    TYPE_FLOAT,       // 浮点类型  
    TYPE_BOOL,        // 布尔类型
    TYPE_VOID,        // 无类型
    TYPE_UNKNOWN      // 未知类型
} DataType;

// 符号表条目结构
typedef struct SymbolEntry {
    char name[50];                // 符号名称
    SymbolType sym_type;          // 符号类型
    DataType data_type;           // 数据类型
    int is_initialized;           // 是否已初始化
    int scope_level;              // 作用域层级
    int memory_address;           // 内存地址（相对偏移）
    int line_declared;            // 声明行号
    struct SymbolEntry* next;     // 下一个符号（用于哈希链表）
} SymbolEntry;

// 符号表结构（使用哈希表实现）
typedef struct {
    SymbolEntry* buckets[100];    // 哈希桶
    int scope_level;              // 当前作用域层级
    int next_address;             // 下一个可用的内存地址
    int count;                    // 符号数量
} SymbolTable;

// 四元式结构体
typedef struct {
    char op[10];        // 运算符
    char arg1[50];      // 操作数1
    char arg2[50];      // 操作数2
    char result[50];    // 结果
} Quadruple;

// 全局变量声明
extern SymbolTable symbol_table;          // 全局符号表
extern Quadruple quadruples[1000];        // 四元式数组
extern int quadCount;                     // 四元式计数器
extern int tempVarCount;                  // 临时变量计数器
extern int labelCount;                    // 标签计数器

// 编译计时结构体
typedef struct {
    double lex_time;      // 词法分析时间
    double parse_time;    // 语法分析时间
    double sem_time;      // 语义分析时间
    double codegen_time;  // 代码生成时间
    double total_time;    // 总编译时间
    clock_t lex_start;    // 词法分析开始时间
    clock_t parse_start;  // 语法分析开始时间  
    clock_t sem_start;    // 语义分析开始时间
    clock_t codegen_start;// 代码生成开始时间
} CompileTiming;

// 全局计时器声明
extern CompileTiming compile_timing;

// 符号表相关函数声明
void init_symbol_table();
void enter_scope();
void exit_scope();
SymbolEntry* insert_symbol(const char* name, SymbolType sym_type, DataType data_type, int line);
SymbolEntry* lookup_symbol(const char* name);
SymbolEntry* lookup_current_scope(const char* name);
void print_symbol_table();
void semantic_check(ASTNode* node);

// 计时相关函数声明
void start_timer(clock_t *timer);
double stop_timer(clock_t start);
void record_lex_time();
void record_parse_time();
void record_sem_time();
void record_codegen_time();
void printCompileTiming();

// 四元式相关函数声明
void generateQuadruples(ASTNode* node);
void printQuadruples();
char* newTemp();

void optimize_quadruples(void);

// 汇编代码生成函数声明
void generateAssembly();
void generateAssemblyToFile(const char* filename);

#endif
