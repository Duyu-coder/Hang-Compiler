# Hang-Compiler
A C-like language compiler implemented with Flex &amp; Bison, supporting AST construction, IR (Quaternary) generation, and x86 assembly backend.
使用 Flex 和 Bison 实现的类 C 语言编译器，支持 AST 构造、IR（四元）生成和 x86 汇编后端。

## 核心特性
- **词法分析**：使用 Flex 处理字符集，支持整数、标识符、运算符及单行/多行注释。
- **语法分析**：基于 Bison 构建 LALR 语法分析器，支持嵌套作用域、If-Else、While 循环等标准文法。
- **语义分析**：通过**符号表**管理标识符属性，实现变量声明检查及类型匹配。
- **中间代码**：生成**四元式 (Quaternary)**，作为前端与后端解耦的中间表示。
- **目标代码**：实现了四元式向 **x86 汇编**的翻译映射，并支持通过 **NASM** 编译为可执行文件。

## 编译流程说明
该编译器遵循经典的五阶段模型：
1. **词法分析** -> 产生 Token 流。
2. **语法分析** -> 构建 **抽象语法树 (AST)**。
3. **语义分析** -> 填充符号表并检查逻辑。
4. **中间代码生成** -> 产生四元式序列。
5. **代码生成** -> 翻译为 `.asm` 汇编文件。

## 运行环境
- Flex / Bison
- GCC (C99 标准)
- NASM (用于汇编后端代码)

## 使用方法
1. **编译编译器**：
   ```bash
   make
