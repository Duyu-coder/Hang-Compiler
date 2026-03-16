// timer.c
#include "common.h"

// 计时相关函数
void start_timer(clock_t *timer) {
    *timer = clock();
}

double stop_timer(clock_t start) {
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

void record_lex_time() {
    compile_timing.lex_time = stop_timer(compile_timing.lex_start);
}

void record_parse_time() {
    compile_timing.parse_time = stop_timer(compile_timing.parse_start);
}

void record_sem_time() {
    compile_timing.sem_time = stop_timer(compile_timing.sem_start);
}

void record_codegen_time() {
    compile_timing.codegen_time = stop_timer(compile_timing.codegen_start);
}

void printCompileTiming() {
    // 确保总编译时间已经计算
    if (compile_timing.total_time == 0) {
        compile_timing.total_time = compile_timing.lex_time + 
                                    compile_timing.parse_time + 
                                    compile_timing.sem_time + 
                                    compile_timing.codegen_time;
    }
    
    printf("\n======= 编译性能分析 ======\n");
    printf("编译阶段\t\t\t耗时(ms)\t\t占比\n");
    printf("----------------------------------------\n");
    
    // 计算核心编译时间（排除其他开销）
    double core_time = compile_timing.lex_time + 
                       compile_timing.parse_time + 
                       compile_timing.sem_time + 
                       compile_timing.codegen_time;
    
    double other_time = compile_timing.total_time - core_time;
    
    // 计算占比
    double lex_percent = 0, parse_percent = 0, sem_percent = 0, codegen_percent = 0, other_percent = 0;
    
    if (compile_timing.total_time > 0) {
        lex_percent = (compile_timing.lex_time / compile_timing.total_time) * 100;
        parse_percent = (compile_timing.parse_time / compile_timing.total_time) * 100;
        sem_percent = (compile_timing.sem_time / compile_timing.total_time) * 100;
        codegen_percent = (compile_timing.codegen_time / compile_timing.total_time) * 100;
        other_percent = (other_time / compile_timing.total_time) * 100;
    }
    
    printf("词法分析\t\t\t%.2f\t\t\t%.1f%%\n", compile_timing.lex_time, lex_percent);
    printf("语法分析\t\t\t%.2f\t\t\t%.1f%%\n", compile_timing.parse_time, parse_percent);
    printf("语义分析\t\t\t%.2f\t\t\t%.1f%%\n", compile_timing.sem_time, sem_percent);
    printf("代码生成\t\t\t%.2f\t\t\t%.1f%%\n", compile_timing.codegen_time, codegen_percent);
    
    if (other_time > 0.01) {  // 只显示有意义的其他时间
        printf("其他(I/O等)\t\t\t%.2f\t\t\t%.1f%%\n", other_time, other_percent);
    }
    
    printf("-----------------------------------------\n");
    printf("总编译时间\t\t\t%.2f\t\t\t100.0%%\n", compile_timing.total_time);
    printf("==========================\n");
}
