CC=g++
CFLAGS=-std=c++11 -Wall

TARGET= ./bin/AVL
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/AVL.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/AVL.o: ${SRC_DIR}/AVL.c
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/AVL.c -o ${OBJ_DIR}/AVL.o

run: all
	${TARGET} ./AVL

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}

