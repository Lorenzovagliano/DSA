CC=g++
CFLAGS=-std=c++11 -Wall -g

TARGET= ./bin/InfixaPosfixa
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/Node.o ${OBJ_DIR}/StackNode.o ${OBJ_DIR}/Stack.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/Node.o: ${INCLUDE_DIR}/Node.hpp ${SRC_DIR}/Node.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Node.cpp -o ${OBJ_DIR}/Node.o

${OBJ_DIR}/StackNode.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/StackNode.hpp ${SRC_DIR}/StackNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/StackNode.cpp -o ${OBJ_DIR}/StackNode.o

${OBJ_DIR}/Stack.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/StackNode.hpp ${INCLUDE_DIR}/Stack.hpp ${SRC_DIR}/Stack.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Stack.cpp -o ${OBJ_DIR}/Stack.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/StackNode.hpp ${INCLUDE_DIR}/Stack.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

run: all
	${TARGET} ./InfixaPosfixa

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}

