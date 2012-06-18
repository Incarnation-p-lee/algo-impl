CC		=gcc
TAR		=$(addprefix ./bin/,a.out)
DYNAMIC		=
OBJS		:=

inc		=./inc
INC		:=-I$(inc)
CFlag		=-c -Wall -g
DFlag		=-shared -fPIC
GPROF		=-pg
LFlag		=


.SUFFIXES:
.SUFFIXES:.o .c
SHELL		=/bin/sh
include ./src/Makefile
OBJS		+=$(obj)

vpath %.c ./src


.PHONY:all clean prepare tar


all:$(TAR)

$(TAR):CFlag+=$(GPROF)
$(TAR):LFlag+=$(GPROF)
$(TAR):$(OBJS)
	$(CC) $(LFlag) -o $@ $^

$(OBJS):%.o:%.c
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
.INTERMEDIATE:$(OBJS)
