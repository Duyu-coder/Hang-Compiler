// assembly.c
#include "common.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateAssembly() {
    FILE* asmFile = fopen("output.asm", "w");
    if (!asmFile) {
        printf("无法创建汇编文件\n");
        return;
    }
    
    // 写入汇编文件头部
    fprintf(asmFile, "section .data\n");
    fprintf(asmFile, "    input_prompt db 'Enter number: ', 0\n");
    fprintf(asmFile, "    input_format db '%%d', 0\n");
    fprintf(asmFile, "    output_format db '%%d', 10, 0  ; 带换行\n");
    fprintf(asmFile, "    newline db 10, 0\n");
    
    // 第一步：收集所有变量和临时变量
    fprintf(asmFile, "    ; 变量声明\n");
    for (int i = 0; i < quadCount; i++) {
        // 处理DECL指令
        if (strcmp(quadruples[i].op, "DECL") == 0) {
            fprintf(asmFile, "    %s dd 0\n", quadruples[i].arg2);
        }
        
        // 收集临时变量
        if (quadruples[i].result[0] == 't' && isdigit(quadruples[i].result[1])) {
            fprintf(asmFile, "    %s dd 0\n", quadruples[i].result);
        }
    }
    
    // 第二步：生成代码段头部
    fprintf(asmFile, "\nsection .text\n");
    fprintf(asmFile, "    global main\n");
    fprintf(asmFile, "    extern printf, scanf\n\n");
    fprintf(asmFile, "main:\n");
    
    // 第三步：生成代码段主体
    for (int i = 0; i < quadCount; i++) {
        fprintf(asmFile, "    ; 四元式 %d: %s %s %s %s\n", 
               i, quadruples[i].op, quadruples[i].arg1, 
               quadruples[i].arg2, quadruples[i].result);
        
        if (strcmp(quadruples[i].op, "IN") == 0) {
            // 输入指令 - 使用scanf系统调用
            fprintf(asmFile, "    ; 输入到 %s\n", quadruples[i].result);
            fprintf(asmFile, "    push %s\n", quadruples[i].result);
            fprintf(asmFile, "    push input_format\n");
            fprintf(asmFile, "    call scanf\n");
            fprintf(asmFile, "    add esp, 8\n");
            
        } else if (strcmp(quadruples[i].op, "=") == 0) {
            // 赋值指令
            if (isdigit(quadruples[i].arg1[0])) {
                // 常量赋值
                fprintf(asmFile, "    mov dword [%s], %s\n", quadruples[i].result, quadruples[i].arg1);
            } else {
                // 变量赋值
                fprintf(asmFile, "    mov eax, [%s]\n", quadruples[i].arg1);
                fprintf(asmFile, "    mov [%s], eax\n", quadruples[i].result);
            }
            
        } else if (strcmp(quadruples[i].op, "*") == 0) {
            // 乘法
            fprintf(asmFile, "    mov eax, [%s]\n", quadruples[i].arg1);
            if (isdigit(quadruples[i].arg2[0])) {
                fprintf(asmFile, "    imul eax, %s\n", quadruples[i].arg2);
            } else {
                fprintf(asmFile, "    imul eax, [%s]\n", quadruples[i].arg2);
            }
            fprintf(asmFile, "    mov [%s], eax\n", quadruples[i].result);
            
        } else if (strcmp(quadruples[i].op, "+") == 0) {
            // 加法
            fprintf(asmFile, "    mov eax, [%s]\n", quadruples[i].arg1);
            if (isdigit(quadruples[i].arg2[0])) {
                fprintf(asmFile, "    add eax, %s\n", quadruples[i].arg2);
            } else {
                fprintf(asmFile, "    add eax, [%s]\n", quadruples[i].arg2);
            }
            fprintf(asmFile, "    mov [%s], eax\n", quadruples[i].result);
            
        } else if (strcmp(quadruples[i].op, ">") == 0) {
            // 大于比较
            fprintf(asmFile, "    mov eax, [%s]\n", quadruples[i].arg1);
            fprintf(asmFile, "    cmp eax, %s\n", quadruples[i].arg2);
            fprintf(asmFile, "    setg al\n");
            fprintf(asmFile, "    movzx eax, al\n");
            fprintf(asmFile, "    mov [%s], eax\n", quadruples[i].result);
            
        } else if (strcmp(quadruples[i].op, "JZ") == 0) {
            // 条件跳转
            fprintf(asmFile, "    cmp dword [%s], 0\n", quadruples[i].arg1);
            fprintf(asmFile, "    je %s\n", quadruples[i].result);
            
        } else if (strcmp(quadruples[i].op, "JMP") == 0) {
            // 无条件跳转
            fprintf(asmFile, "    jmp %s\n", quadruples[i].result);
            
        } else if (strcmp(quadruples[i].op, "LABEL") == 0) {
            // 标签定义
            fprintf(asmFile, "%s:\n", quadruples[i].arg1);
            
        } else if (strcmp(quadruples[i].op, "OUT") == 0) {
            // 输出指令 - 使用printf系统调用
            fprintf(asmFile, "    ; 输出 %s\n", quadruples[i].arg1);
            fprintf(asmFile, "    push dword [%s]\n", quadruples[i].arg1);
            fprintf(asmFile, "    push output_format\n");
            fprintf(asmFile, "    call printf\n");
            fprintf(asmFile, "    add esp, 8\n");
        }
        
        fprintf(asmFile, "\n");
    }
    
    // 程序退出
    fprintf(asmFile, "    ; 程序退出\n");
    fprintf(asmFile, "    mov eax, 0      ; 返回0\n");
    fprintf(asmFile, "    ret\n");
    
    fclose(asmFile);
    printf("汇编代码已生成到 output.asm\n");
}

// 可选：在屏幕上显示汇编代码
void printAssembly() {
    printf("\n生成的汇编代码：\n");
    printf("=================================\n");
    
    // 这里可以读取并显示刚才生成的output.asm文件内容
    FILE* asmFile = fopen("output.asm", "r");
    if (asmFile) {
        char line[256];
        while (fgets(line, sizeof(line), asmFile)) {
            printf("%s", line);
        }
        fclose(asmFile);
    }
    printf("=================================\n");
}
