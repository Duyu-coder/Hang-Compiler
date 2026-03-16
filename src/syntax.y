%{
#include "common.h"
#include "optimize.h"
// 声明词法分析器函数
extern int yylex(void);
extern int yyparse(void);
extern FILE* yyin;

// 错误处理函数声明
void yyerror(const char* s);

// 语法树根节点声明
extern ASTNode* ast_root;
%}

// 定义语义值类型
%union {
    char* string_value;
    ASTNode* node;
}

// 为token和nonterminal指定语义值类型
%token <string_value> TOK_ID TOK_INT TOK_FLOAT TOK_TRUE TOK_FALSE
%token <string_value> TOK_INT_TYPE TOK_FLOAT_TYPE TOK_BOOL_TYPE
%token TOK_HANG TOK_IN TOK_OUT TOK_WHEN
%token TOK_ADD TOK_SUB TOK_MUL TOK_DIV
%token TOK_ASSIGN TOK_FEN TOK_DOU TOK_LY TOK_RY TOK_LH TOK_RH
%token TOK_ERROR

// 添加比较运算符token
%token TOK_GT TOK_LT TOK_GE TOK_LE TOK_EQ TOK_NE

// 定义运算符优先级和结合性
%left TOK_ADD TOK_SUB
%left TOK_MUL TOK_DIV
%nonassoc TOK_GT TOK_LT TOK_GE TOK_LE TOK_EQ TOK_NE

// 为non-terminal指定类型
%type <node> program statements statement
%type <node> declaration_statement assignment_statement input_statement output_statement
%type <node> when_statement type_specifier identifiers expression condition

%%

// 程序由hang块组成 - 压缩hang_block中间节点
program:
    TOK_HANG TOK_LH statements TOK_RH
    {
        $$ = createNode(NODE_PROGRAM, "hang_program");
        // 将语句链表的所有节点添加为子节点
        ASTNode* current = $3;
        while (current != NULL) 
        {
            ASTNode* next = current->next_sibling;
            current->next_sibling = NULL; // 清除兄弟指针，转换为父子关系
            addChild($$, current);
            current = next;
        }
        ast_root = $$;
        printf("语法分析: 识别到hang程序块\n");
    }
    ;

// 语句序列
statements:
    statement
    {
        $$ = $1;
    }
    | statements statement
    {
        // 将新语句添加为兄弟节点
        addSibling($1, $2);
        $$ = $1;
    }
    ;

// 语句定义
statement:
    declaration_statement
    {
        $$ = $1;
    }
    | assignment_statement
    {
        $$ = $1;
    }
    | input_statement
    {
        $$ = $1;
    }
    | output_statement
    {
        $$ = $1;
    }
    | when_statement
    {
        $$ = $1;
    }
    | expression TOK_FEN
    {
        $$ = $1;
    }
    ;

// 声明语句
declaration_statement:
    type_specifier identifiers TOK_FEN
    {
        $$ = createNode(NODE_DECLARATION, "decl");
        addChild($$, $1);  // 类型
        addChild($$, $2);  // 标识符列表
    }
    | type_specifier TOK_ID TOK_ASSIGN expression TOK_FEN
    {
        $$ = createNode(NODE_DECLARATION, "decl_init");
        addChild($$, $1);  // 类型
        ASTNode* id_node = createNode(NODE_IDENTIFIER, $2);
        addChild($$, id_node);
        addChild($$, $4);  // 初始值表达式
    }
    ;

// 类型说明符
type_specifier:
    TOK_INT_TYPE
    {
        $$ = createNode(NODE_TYPE, "int");
    }
    | TOK_FLOAT_TYPE
    {
        $$ = createNode(NODE_TYPE, "float");
    }
    | TOK_BOOL_TYPE
    {
        $$ = createNode(NODE_TYPE, "bool");
    }
    ;

// 标识符列表
identifiers:
    TOK_ID
    {
        $$ = createNode(NODE_IDENTIFIER, $1);
    }
    | identifiers TOK_DOU TOK_ID
    {
        // 将新标识符添加为兄弟节点
        addSibling($1, createNode(NODE_IDENTIFIER, $3));
        $$ = $1;
    }
    ;

// 赋值语句
assignment_statement:
    TOK_ID TOK_ASSIGN expression TOK_FEN
    {
        $$ = createNode(NODE_ASSIGNMENT, "=");
        addChild($$, createNode(NODE_IDENTIFIER, $1));
        addChild($$, $3);
    }
    ;

// 输入语句 - 只接受标识符
input_statement:
    TOK_IN TOK_LY TOK_ID TOK_RY TOK_FEN
    {
        $$ = createNode(NODE_INPUT, "in");
        addChild($$, createNode(NODE_IDENTIFIER, $3));
    }
    ;

// 输出语句
output_statement:
    TOK_OUT TOK_LY expression TOK_RY TOK_FEN
    {
        $$ = createNode(NODE_OUTPUT, "out");
        addChild($$, $3);
    }
    ;

// when语句
when_statement:
    TOK_WHEN TOK_LY condition TOK_RY TOK_LH statements TOK_RH
    {
        $$ = createNode(NODE_WHEN, "when");
        addChild($$, $3);  // 条件
        addChild($$, $6);  // 语句块
    }
    ;

// 条件表达式 - 修复规约冲突
condition:
    expression
    {
        $$ = $1;
    }
    | expression TOK_GT expression
    {
        $$ = createNode(NODE_OPERATOR, ">");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_LT expression
    {
        $$ = createNode(NODE_OPERATOR, "<");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_GE expression
    {
        $$ = createNode(NODE_OPERATOR, ">=");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_LE expression
    {
        $$ = createNode(NODE_OPERATOR, "<=");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_EQ expression
    {
        $$ = createNode(NODE_OPERATOR, "==");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_NE expression
    {
        $$ = createNode(NODE_OPERATOR, "!=");
        addChild($$, $1);
        addChild($$, $3);
    }
    ;

// 表达式 - 保留布尔字面量
expression:
    TOK_ID
    {
        $$ = createNode(NODE_IDENTIFIER, $1);
    }
    | TOK_INT
    {
        $$ = createNode(NODE_CONSTANT, $1);
    }
    | TOK_FLOAT
    {
        $$ = createNode(NODE_CONSTANT, $1);
    }
    | TOK_TRUE
    {
        $$ = createNode(NODE_CONSTANT, "true");
    }
    | TOK_FALSE
    {
        $$ = createNode(NODE_CONSTANT, "false");
    }
    | TOK_LY expression TOK_RY
    {
        $$ = $2;  // 括号表达式：直接返回内部表达式
    }
    | expression TOK_ADD expression
    {
        $$ = createNode(NODE_OPERATOR, "+");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_SUB expression
    {
        $$ = createNode(NODE_OPERATOR, "-");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_MUL expression
    {
        $$ = createNode(NODE_OPERATOR, "*");
        addChild($$, $1);
        addChild($$, $3);
    }
    | expression TOK_DIV expression
    {
        $$ = createNode(NODE_OPERATOR, "/");
        addChild($$, $1);
        addChild($$, $3);
    }
    ;

%%

// 全局语法树根节点
ASTNode* ast_root = NULL;

// 错误处理函数
void yyerror(const char* s) 
{
    extern int yylineno;
    fprintf(stderr, "语法错误 (行%d): %s\n", yylineno, s);
}

int main(int argc, char* argv[]) 
{
    // 设置输入文件
    if (argc > 1) 
    {
        yyin = fopen(argv[1], "r");
        if (!yyin) 
        {
            fprintf(stderr, "无法打开文件: %s\n", argv[1]);
            return 1;
        }
    } 
    else 
    {
        printf("未检测到输入文件，请输入文件后重试\n");
        return 1;
    }
    
    printf("开始语法分析...\n");
    printf("=================================\n");
    
    // 记录总编译开始时间（用于统计）
    clock_t total_start = clock();
    
    // 记录词法分析开始时间（在yyparse之前）
    start_timer(&compile_timing.lex_start);
    
    // 记录语法分析开始时间
    start_timer(&compile_timing.parse_start);
    
    // 调用语法分析器（内部会调用词法分析器）
    int result = yyparse();
    
    // 记录语法分析结束时间
    record_parse_time();
    
    // 记录词法分析结束时间（在yyparse之后）
    record_lex_time();
    
    if (result == 0) 
    {
        printf("=================================\n");
        printf("语法分析成功完成!\n");
        
        // 记录语义分析开始时间
        start_timer(&compile_timing.sem_start);
        
        // 打印语法树（语义分析的一部分）
        printf("\n======= 抽象语法树(AST) =======\n");
        if (ast_root) 
        {
            printAST(ast_root, 0);
        } 
        else 
        {
            printf("语法树为空\n");
        }
        printf("======= AST结束 =======\n");
        
        // 记录语义分析结束时间
        record_sem_time();
        
        // 记录代码生成开始时间
        start_timer(&compile_timing.codegen_start);
        
        // 生成四元式
        if (ast_root) 
        {
            generateQuadruples(ast_root);
            printQuadruples();
            
	    // 执行优化
	    printf("\n=== 中间代码优化 ===\n");
	    optimize_quadruples();

	    printQuadruples();  // 显示优化后的四元式

            // 生成汇编代码到文件
            printf("\n=== 生成汇编代码 ===\n");    

            // 确定输出文件名
            char asmFilename[256];
            strcpy(asmFilename, argv[1]);
            char* dot = strrchr(asmFilename, '.');
            if (dot) *dot = '\0';
            strcat(asmFilename, ".asm");
            
            // 生成汇编文件
            generateAssemblyToFile(asmFilename);
            
            // 同时在屏幕上显示汇编代码（可选）
            printf("\n======= 生成的汇编代码 =======\n");
            generateAssembly();
            printf("======= 汇编代码结束 =======\n");
        }
        
        // 记录代码生成结束时间
        record_codegen_time();
        
    } 
    else 
    {
        printf("=================================\n");
        printf("语法分析失败!\n");
    }
    
    // 初始化符号表
    init_symbol_table();
    
    // 记录语义分析开始时间
    start_timer(&compile_timing.sem_start);
    
    // 执行语义分析
    if (result == 0 && ast_root) {
        printf("\n=== 开始语义分析 ===\n");
        semantic_check(ast_root);
        printf("语义分析完成\n");
    }
    
    // 记录语义分析结束时间
    record_sem_time();
    
    // 打印符号表
    print_symbol_table();
 
    // 打印符号表
    //printSymbolTable();
    
    // 计算总编译时间
    compile_timing.total_time = ((double)(clock() - total_start)) / CLOCKS_PER_SEC * 1000.0;
    
    // 打印编译性能分析
    printCompileTiming();
    
    // 释放语法树内存
    if (ast_root) 
    {
        freeAST(ast_root);
        ast_root = NULL;
    }
    
    if (argc > 1) 
    {
        fclose(yyin);
    }
    
    return result;
}
