# makefile for one C/Asm module on Linux - 2005/BHO1
# 

PRJ=ptr

CC=gcc
CFLAGS=-g -Wall 


OBJ=pointers-prints.o 
#${PRJ}.o
SRC=pointers-prints.c

all : ${SRC} ${OBJ} ${PRJ} ass

${OBJ} : ${SRC}
	$(CC) $(CFLAGS) -c ${SRC}

ass : ${SRC}
	$(CC) $(CFLAGS) -S ${SRC}

${PRJ} : ${OBJ}
	$(CC) $(CFLAGS) -o ${PRJ} ${OBJ}


clean : 
	\rm *.o *.s $(PRJ)


