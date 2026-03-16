%{
#include "common.h"
#include "syntax.tab.h"

// 不再需要定义 symbolTable 和 symbolCount
// 词法分析器只需要返回 token，符号表功能已经移到了语义分析阶段

// 如果需要，可以保留简单的行号计数（如果需要行号信息）
int line_number = 1;
%}

%option noyywrap
%option noinput
%option nounput

SPACE   [ \t\n]+
DIGIT   [0-9]
LETTER  [a-zA-Z]
INT_NUM [1-9]{DIGIT}*|0
FLOAT_NUM {INT_NUM}"."{DIGIT}+  
IDENT   ({LETTER}|_)({LETTER}|{DIGIT}|_)*

%%
\n        { line_number++; }

{SPACE}   { /* 跳过空白字符 */ }

"hang"    { return TOK_HANG; }
"in"      { return TOK_IN; }      
"out"     { return TOK_OUT; }  
"when"    { return TOK_WHEN; }
"true"    { yylval.string_value = strdup("true"); return TOK_TRUE; }
"false"   { yylval.string_value = strdup("false"); return TOK_FALSE; }

"int"     { return TOK_INT_TYPE; }
"float"   { return TOK_FLOAT_TYPE; }
"bool"    { return TOK_BOOL_TYPE; }

">"       { return TOK_GT; }
"<"       { return TOK_LT; }
">="      { return TOK_GE; }
"<="      { return TOK_LE; }
"=="      { return TOK_EQ; }
"!="      { return TOK_NE; }

{IDENT}   { 
    yylval.string_value = strdup(yytext);
    return TOK_ID; 
}
{INT_NUM} { 
    yylval.string_value = strdup(yytext);
    return TOK_INT; 
}
{FLOAT_NUM} { 
    yylval.string_value = strdup(yytext);
    return TOK_FLOAT; 
}

"+"       { return TOK_ADD; }
"-"       { return TOK_SUB; }
"*"       { return TOK_MUL; }
"/"       { return TOK_DIV; }

"="       { return TOK_ASSIGN; }
";"       { return TOK_FEN; }
","       { return TOK_DOU; }
"("       { return TOK_LY; }
")"       { return TOK_RY; }
"{"       { return TOK_LH; }
"}"       { return TOK_RH; }  

.         { 
    fprintf(stderr, "词法错误（行 %d）: 无法识别的字符 '%c'\n", line_number, yytext[0]);
    return TOK_ERROR; 
}
%%
