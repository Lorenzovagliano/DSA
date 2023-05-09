CC=g++
CFLAGS= -Wall -g

TARGET= ./bin/InfixaPosfixa
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/TreeNode.o ${OBJ_DIR}/NodeStackNode.o ${OBJ_DIR}/NodeStack.o ${OBJ_DIR}/StringStackNode.o ${OBJ_DIR}/StringStack.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/TreeNode.o: ${INCLUDE_DIR}/TreeNode.hpp ${SRC_DIR}/TreeNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/TreeNode.cpp -o ${OBJ_DIR}/TreeNode.o

${OBJ_DIR}/NodeStackNode.o: ${INCLUDE_DIR}/TreeNode.hpp ${INCLUDE_DIR}/NodeStackNode.hpp ${SRC_DIR}/NodeStackNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/NodeStackNode.cpp -o ${OBJ_DIR}/NodeStackNode.o

${OBJ_DIR}/NodeStack.o: ${INCLUDE_DIR}/TreeNode.hpp ${INCLUDE_DIR}/NodeStackNode.hpp ${INCLUDE_DIR}/NodeStack.hpp ${SRC_DIR}/NodeStack.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/NodeStack.cpp -o ${OBJ_DIR}/NodeStack.o

${OBJ_DIR}/StringStackNode.o: ${INCLUDE_DIR}/StringStackNode.hpp ${SRC_DIR}/StringStackNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/StringStackNode.cpp -o ${OBJ_DIR}/StringStackNode.o

${OBJ_DIR}/StringStack.o: ${INCLUDE_DIR}/StringStackNode.hpp ${INCLUDE_DIR}/StringStack.hpp ${SRC_DIR}/StringStack.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/StringStack.cpp -o ${OBJ_DIR}/StringStack.o


${OBJ_DIR}/main.o: ${INCLUDE_DIR}/TreeNode.hpp ${INCLUDE_DIR}/NodeStackNode.hpp ${INCLUDE_DIR}/NodeStack.hpp ${INCLUDE_DIR}/StringStackNode.hpp ${INCLUDE_DIR}/StringStack.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

run: all
	${TARGET} ./InfixaPosfixa

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}

