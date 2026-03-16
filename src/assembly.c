// assembly.c
#include "common.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void generateAssembly() {
    printf("section .data\n");
    
    // 第一步：收集所有变量和临时变量
    printf("    ; 变量声明\n");
    
    char* declarations[200];
    int declCount = 0;
    
    // 函数：检查是否已经在声明列表中
    int is_declared(const char* name) {
        for (int i = 0; i < declCount; i++) {
            if (strcmp(declarations[i], name) == 0) {
                return 1;
            }
        }
        return 0;
    }
    
    // 函数：添加声明
    void add_declaration(const char* name) {
        if (!is_declared(name)) {
            declarations[declCount] = (char*)malloc(strlen(name) + 1);
            strcpy(declarations[declCount], name);
            declCount++;
        }
    }
    
    // 从四元式中收集所有变量
    for (int i = 0; i < quadCount; i++) {
        // 收集结果变量
        if (strlen(quadruples[i].result) > 0 && 
            strcmp(quadruples[i].result, "_") != 0 &&
            quadruples[i].result[0] != 'L') {  // 跳过标签
            
            // 如果是临时变量（t开头后跟数字）
            if (quadruples[i].result[0] == 't' && isdigit(quadruples[i].result[1])) {
                add_declaration(quadruples[i].result);
            }
            // 如果是用户变量（字母开头）
            else if (isalpha(quadruples[i].result[0])) {
                add_declaration(quadruples[i].result);
            }
        }
        
        // 收集操作数1
        if (strlen(quadruples[i].arg1) > 0 && 
            strcmp(quadruples[i].arg1, "_") != 0 &&
            !isdigit(quadruples[i].arg1[0]) &&  // 跳过数字常量
            quadruples[i].arg1[0] != 'L') {     // 跳过标签
            
            if (isalpha(quadruples[i].arg1[0])) {
                add_declaration(quadruples[i].arg1);
            }
        }
        
        // 收集操作数2
        if (strlen(quadruples[i].arg2) > 0 && 
            strcmp(quadruples[i].arg2, "_") != 0 &&
            !isdigit(quadruples[i].arg2[0]) &&  // 跳过数字常量
            quadruples[i].arg2[0] != 'L') {     // 跳过标签
            
            if (isalpha(quadruples[i].arg2[0])) {
                add_declaration(quadruples[i].arg2);
            }
        }
    }
    
    // 打印所有变量声明
    for (int i = 0; i < declCount; i++) {
        printf("    %s dd 0\n", declarations[i]);
        free(declarations[i]);  // 释放内存
    }
    
    // 添加输入输出缓冲区
    printf("\n    ; 输入输出缓冲区\n");
    printf("    input_buffer times 16 db 0\n");
    printf("    output_buffer times 16 db 0\n");
    printf("    newline db 0xA\n");
    
    printf("\nsection .text\n");
    printf("    global _start\n\n");
    
    // 添加必要的子程序
    printf("; 将整数转换为字符串的子程序\n");
    printf("; 输入: EAX = 整数, RDI = 缓冲区地址\n");
    printf("; 输出: RCX = 字符串长度\n");
    printf("int_to_string:\n");
    printf("    push rdi        ; 保存原始缓冲区地址\n");
    printf("    mov r8, rdi     ; 使用r8作为工作指针\n");
    printf("    mov ebx, 10\n");
    printf("    xor ecx, ecx\n");
    printf("    \n");
    printf("    ; 处理0的情况\n");
    printf("    test eax, eax\n");
    printf("    jnz .convert_loop\n");
    printf("    mov byte [r8], '0'\n");
    printf("    mov ecx, 1\n");
    printf("    pop rdi\n");
    printf("    ret\n");
    printf("    \n");
    printf(".convert_loop:\n");
    printf("    xor edx, edx\n");
    printf("    div ebx\n");
    printf("    add dl, '0'\n");
    printf("    mov [r8], dl\n");
    printf("    inc r8\n");
    printf("    inc ecx\n");
    printf("    test eax, eax\n");
    printf("    jnz .convert_loop\n");
    printf("    \n");
    printf("    ; 反转字符串\n");
    printf("    mov rsi, rdi    ; 起始地址\n");
    printf("    mov r9, r8\n");
    printf("    dec r9          ; 结束地址\n");
    printf(".reverse_loop:\n");
    printf("    cmp rsi, r9\n");
    printf("    jge .reverse_done\n");
    printf("    mov al, [rsi]\n");
    printf("    mov bl, [r9]\n");
    printf("    mov [rsi], bl\n");
    printf("    mov [r9], al\n");
    printf("    inc rsi\n");
    printf("    dec r9\n");
    printf("    jmp .reverse_loop\n");
    printf("    \n");
    printf(".reverse_done:\n");
    printf("    pop rdi\n");
    printf("    ret\n\n");
    
    printf("; 将字符串转换为整数的子程序\n");
    printf("; 输入: RSI = 字符串地址\n");
    printf("; 输出: EAX = 整数\n");
    printf("string_to_int:\n");
    printf("    xor eax, eax\n");
    printf("    xor ebx, ebx\n");
    printf(".convert:\n");
    printf("    mov bl, [rsi]\n");
    printf("    cmp bl, 0xA    ; 换行符\n");
    printf("    je .done\n");
    printf("    cmp bl, '0'\n");
    printf("    jb .done\n");
    printf("    cmp bl, '9'\n");
    printf("    ja .done\n");
    printf("    sub bl, '0'\n");
    printf("    imul eax, 10\n");
    printf("    add eax, ebx\n");
    printf("    inc rsi\n");
    printf("    jmp .convert\n");
    printf(".done:\n");
    printf("    ret\n\n");
    
    printf("_start:\n");
    printf("    ; 确保栈对齐（16字节边界）\n");
    printf("    and rsp, -16\n");
    
    // 第二步：生成代码段
    // 生成代码段
for (int i = 0; i < quadCount; i++) {
    printf("    ; 四元式 %d: %s %s %s %s\n", 
           i, quadruples[i].op, quadruples[i].arg1, 
           quadruples[i].arg2, quadruples[i].result);
    
    if (strcmp(quadruples[i].op, "IN") == 0) {
        // 输入指令
        printf("    ; 读取输入到 %s\n", quadruples[i].result);
        printf("    mov rax, 0          ; sys_read\n");
        printf("    mov rdi, 0          ; stdin\n");
        printf("    mov rsi, input_buffer\n");
        printf("    mov rdx, 16         ; 缓冲区大小\n");
        printf("    syscall\n");
        printf("    \n");
        printf("    mov rsi, input_buffer\n");
        printf("    call string_to_int\n");
        printf("    mov [%s], eax\n", quadruples[i].result);
        
    } else if (strcmp(quadruples[i].op, "=") == 0) {
        // 赋值指令
        if (isdigit(quadruples[i].arg1[0])) {
            printf("    mov dword [%s], %s\n", quadruples[i].result, quadruples[i].arg1);
        } else {
            printf("    mov eax, [%s]\n", quadruples[i].arg1);
            printf("    mov [%s], eax\n", quadruples[i].result);
        }
        
    } else if (strcmp(quadruples[i].op, "+") == 0) {
        // 加法
        printf("    mov eax, [%s]\n", quadruples[i].arg1);
        if (isdigit(quadruples[i].arg2[0])) {
            printf("    add eax, %s\n", quadruples[i].arg2);
        } else {
            printf("    add eax, [%s]\n", quadruples[i].arg2);
        }
        printf("    mov [%s], eax\n", quadruples[i].result);
        
    } else if (strcmp(quadruples[i].op, "-") == 0) {
        // 减法
        printf("    mov eax, [%s]\n", quadruples[i].arg1);
        if (isdigit(quadruples[i].arg2[0])) {
            printf("    sub eax, %s\n", quadruples[i].arg2);
        } else {
            printf("    sub eax, [%s]\n", quadruples[i].arg2);
        }
        printf("    mov [%s], eax\n", quadruples[i].result);
        
    } else if (strcmp(quadruples[i].op, "*") == 0) {
        // 乘法
        printf("    mov eax, [%s]\n", quadruples[i].arg1);
        if (isdigit(quadruples[i].arg2[0])) {
            printf("    imul eax, %s\n", quadruples[i].arg2);
        } else {
            printf("    imul eax, [%s]\n", quadruples[i].arg2);
        }
        printf("    mov [%s], eax\n", quadruples[i].result);
        
    } else if (strcmp(quadruples[i].op, "/") == 0) {
        // 除法 - 特别注意：idiv 需要特殊处理
        printf("    mov eax, [%s]\n", quadruples[i].arg1);
        printf("    cdq                    ; 扩展 eax 到 edx:eax 用于有符号除法\n");
        if (isdigit(quadruples[i].arg2[0])) {
            printf("    mov ebx, %s\n", quadruples[i].arg2);
            printf("    idiv ebx            ; eax = edx:eax / ebx, edx = 余数\n");
        } else {
            printf("    idiv dword [%s]     ; eax = edx:eax / [%s], edx = 余数\n", 
                   quadruples[i].arg2, quadruples[i].arg2);
        }
        printf("    mov [%s], eax         ; 存储商\n", quadruples[i].result);
        
    } else if (strcmp(quadruples[i].op, ">") == 0) {
        // 大于比较
        printf("    mov eax, [%s]\n", quadruples[i].arg1);
        if (isdigit(quadruples[i].arg2[0])) {
            printf("    cmp eax, %s\n", quadruples[i].arg2);
        } else {
            printf("    cmp eax, [%s]\n", quadruples[i].arg2);
        }
        printf("    setg al\n");
        printf("    movzx eax, al\n");
        printf("    mov [%s], eax\n", quadruples[i].result);
        
    } else if (strcmp(quadruples[i].op, "JZ") == 0) {
        // 条件跳转
        printf("    cmp dword [%s], 0\n", quadruples[i].arg1);
        printf("    je %s\n", quadruples[i].result);
        
    } else if (strcmp(quadruples[i].op, "LABEL") == 0) {
        // 标签定义
        printf("%s:\n", quadruples[i].arg1);
        
    } else if (strcmp(quadruples[i].op, "OUT") == 0) {
        // 输出指令
        printf("    ; 输出 %s\n", quadruples[i].arg1);
        printf("    mov eax, [%s]\n", quadruples[i].arg1);
        printf("    mov rdi, output_buffer\n");
        printf("    call int_to_string\n");
        printf("    \n");
        printf("    ; 输出数字\n");
        printf("    mov rax, 1          ; sys_write\n");
        printf("    mov rdi, 1          ; stdout\n");
        printf("    mov rsi, output_buffer\n");
        printf("    mov rdx, rcx        ; 字符串长度\n");
        printf("    syscall\n");
        printf("    \n");
        printf("    ; 输出换行\n");
        printf("    mov rax, 1\n");
        printf("    mov rdi, 1\n");
        printf("    mov rsi, newline\n");
        printf("    mov rdx, 1\n");
        printf("    syscall\n");
    }
    
    printf("\n");
}

    // 程序退出 - 修复段错误
    printf("    ; 程序退出\n");
    printf("    mov eax, 60           ; sys_exit\n");
    printf("    xor edi, edi          ; 退出状态 0\n");
    printf("    syscall\n");

}

// 生成汇编文件
void generateAssemblyToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("错误: 无法创建文件 %s\n", filename);
        return;
    }
    
    // 保存原来的 stdout
    FILE* original_stdout = stdout;
    
    // 重定向 stdout 到文件
    stdout = file;
    
    // 生成汇编代码到文件
    generateAssembly();
    
    // 恢复 stdout
    fclose(file);
    stdout = original_stdout;
    
    printf("已生成汇编文件: %s\n", filename);
}

// 打印汇编代码（辅助函数）
void printAssembly() {
    printf("\n生成的汇编代码：\n");
    printf("=================================\n");
    
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
