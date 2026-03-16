#!/bin/bash

# build.sh - Hang语言自动化构建脚本（简化版）

if [ $# -eq 0 ]; then
    echo "用法: $0 <hang源文件>"
    echo "示例: $0 test.hang"
    exit 1
fi

SOURCE_FILE="$1"
BASE_NAME="${SOURCE_FILE%.*}"

echo "🚀 开始构建 Hang 程序: $SOURCE_FILE"

# 步骤1: 编译 Hang 编译器
echo "📝 步骤1: 编译 Hang 编译器..."
make clean
make
if [ $? -ne 0 ]; then
    echo "❌ 编译器编译失败"
    exit 1
fi

# 步骤2: 运行编译器（会自动生成 .asm 文件）
echo "🔧 步骤2: 编译 Hang 程序并生成汇编代码..."
./compiler "$SOURCE_FILE"
if [ $? -ne 0 ]; then
    echo "❌ Hang 程序编译失败"
    exit 1
fi

# 检查是否生成了汇编文件
if [ ! -f "${BASE_NAME}.asm" ]; then
    echo "❌ 汇编文件未生成: ${BASE_NAME}.asm"
    exit 1
fi

echo "✅ 已生成汇编文件: ${BASE_NAME}.asm"

# 步骤3: 汇编和链接
echo "🔨 步骤3: 汇编和链接..."

echo "执行: nasm -f elf64 ${BASE_NAME}.asm -o ${BASE_NAME}.o"
nasm -f elf64 "${BASE_NAME}.asm" -o "${BASE_NAME}.o"
if [ $? -ne 0 ]; then
    echo "❌ 汇编失败"
    exit 1
fi

echo "执行: ld ${BASE_NAME}.o -o ${BASE_NAME}"
ld "${BASE_NAME}.o" -o "${BASE_NAME}"
if [ $? -ne 0 ]; then
    echo "❌ 链接失败"
    exit 1
fi

# 步骤4: 清理和显示结果
echo "🧹 清理临时文件..."
rm -f "${BASE_NAME}.o"

echo ""
echo "🎉 构建成功!"
echo "📋 构建结果:"
echo "   - 可执行文件: ./${BASE_NAME}"
echo "   - 汇编文件: ${BASE_NAME}.asm"
echo ""
echo "▶️  运行程序: ./${BASE_NAME}"
