# Makefile
CC = gcc
CFLAGS = -g -Wall
LEX = flex
YACC = bison
YFLAGS = -d

# 添加 optimize.o 到目标文件列表
OBJS = lex.yy.o syntax.tab.o ast.o codegen.o assembly.o symtab.o semantic.o common.o optimize.o

compiler: $(OBJS)
	$(CC) $(CFLAGS) -o compiler $(OBJS) -lfl

syntax.tab.c syntax.tab.h: syntax.y
	$(YACC) $(YFLAGS) syntax.y

lex.yy.c: lexical.l syntax.tab.h
	$(LEX) lexical.l

# 添加 optimize.o 的编译规则
optimize.o: optimize.c common.h
	$(CC) $(CFLAGS) -c optimize.c -o optimize.o

symtab.o: symtab.c common.h
	$(CC) $(CFLAGS) -c symtab.c -o symtab.o

semantic.o: semantic.c common.h
	$(CC) $(CFLAGS) -c semantic.c -o semantic.o

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c -o common.o

codegen.o: codegen.c common.h
	$(CC) $(CFLAGS) -c codegen.c -o codegen.o

# 通用规则，处理其他 .c 文件（如 ast.c, assembly.c 等）
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o compiler lex.yy.c syntax.tab.c syntax.tab.h *.asm

.PHONY: clean
