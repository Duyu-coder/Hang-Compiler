section .data
    ; 变量声明
    a dd 0
    b dd 0
    c dd 0
    t0 dd 0
    t1 dd 0
    t2 dd 0
    t3 dd 0
    result dd 0
    t4 dd 0

    ; 输入输出缓冲区
    input_buffer times 16 db 0
    output_buffer times 16 db 0
    newline db 0xA

section .text
    global _start

; 将整数转换为字符串的子程序
; 输入: EAX = 整数, RDI = 缓冲区地址
; 输出: RCX = 字符串长度
int_to_string:
    push rdi        ; 保存原始缓冲区地址
    mov r8, rdi     ; 使用r8作为工作指针
    mov ebx, 10
    xor ecx, ecx
    
    ; 处理0的情况
    test eax, eax
    jnz .convert_loop
    mov byte [r8], '0'
    mov ecx, 1
    pop rdi
    ret
    
.convert_loop:
    xor edx, edx
    div ebx
    add dl, '0'
    mov [r8], dl
    inc r8
    inc ecx
    test eax, eax
    jnz .convert_loop
    
    ; 反转字符串
    mov rsi, rdi    ; 起始地址
    mov r9, r8
    dec r9          ; 结束地址
.reverse_loop:
    cmp rsi, r9
    jge .reverse_done
    mov al, [rsi]
    mov bl, [r9]
    mov [rsi], bl
    mov [r9], al
    inc rsi
    dec r9
    jmp .reverse_loop
    
.reverse_done:
    pop rdi
    ret

; 将字符串转换为整数的子程序
; 输入: RSI = 字符串地址
; 输出: EAX = 整数
string_to_int:
    xor eax, eax
    xor ebx, ebx
.convert:
    mov bl, [rsi]
    cmp bl, 0xA    ; 换行符
    je .done
    cmp bl, '0'
    jb .done
    cmp bl, '9'
    ja .done
    sub bl, '0'
    imul eax, 10
    add eax, ebx
    inc rsi
    jmp .convert
.done:
    ret

_start:
    ; 确保栈对齐（16字节边界）
    and rsp, -16
    ; 四元式 0: IN _ _ a
    ; 读取输入到 a
    mov rax, 0          ; sys_read
    mov rdi, 0          ; stdin
    mov rsi, input_buffer
    mov rdx, 16         ; 缓冲区大小
    syscall
    
    mov rsi, input_buffer
    call string_to_int
    mov [a], eax

    ; 四元式 1: = 3 _ b
    mov dword [b], 3

    ; 四元式 2: = 4 _ c
    mov dword [c], 4

    ; 四元式 3: + a 3 t0
    mov eax, [a]
    add eax, 3
    mov [t0], eax

    ; 四元式 4: * t0 2 t1
    mov eax, [t0]
    imul eax, 2
    mov [t1], eax

    ; 四元式 5: = 2 _ t2
    mov dword [t2], 2

    ; 四元式 6: - t1 t2 t3
    mov eax, [t1]
    sub eax, [t2]
    mov [t3], eax

    ; 四元式 7: = t3 _ result
    mov eax, [t3]
    mov [result], eax

    ; 四元式 8: > result 10 t4
    mov eax, [result]
    cmp eax, 10
    setg al
    movzx eax, al
    mov [t4], eax

    ; 四元式 9: JZ t4 _ L0
    cmp dword [t4], 0
    je L0

    ; 四元式 10: OUT result _ _
    ; 输出 result
    mov eax, [result]
    mov rdi, output_buffer
    call int_to_string
    
    ; 输出数字
    mov rax, 1          ; sys_write
    mov rdi, 1          ; stdout
    mov rsi, output_buffer
    mov rdx, rcx        ; 字符串长度
    syscall
    
    ; 输出换行
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    ; 四元式 11: LABEL L0 _ _
L0:

    ; 程序退出
    mov eax, 60           ; sys_exit
    xor edi, edi          ; 退出状态 0
    syscall
