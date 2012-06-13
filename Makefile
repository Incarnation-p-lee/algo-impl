.SUFFIXES:
.SUFFIXES:.o .c
SHELL		=/bin/sh
include ./src/Makefile

vpath %.c ./src

CC		=gcc

TAR		=$(addprefix ./bin/,a.out)
DYNAMIC		=

inc		=./inc
INC		:=-I$(inc)
CFlag		=-c -Wall -g
DFlag		=-shared -fPID
GPROF		=-pg
LFlag		=

.PHONY:all clean prepare tar


all:$(TAR)

$(TAR):CFlag+=$(GPROF)
$(TAR):LFlag+=$(GPROF)
$(TAR):$(obj)
	$(CC) $(LFlag) -o $@ $^

$(obj):%.o:%.c
	$(CC) $(CFlag) $(INC) -o $@ $<

.PHONY:clean prepare

clean:
	-rm -f $(TAR) 

tar:
	tar -zcvf ../code-backup/algo-pearl.`date +"%y-%m-%d"`.tar.gz ./

prepare:
	mkdir inc
	mkdir src
	mkdir bin
.INTERMEDIATE:$(obj)
