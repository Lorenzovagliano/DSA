CC=g++
CFLAGS= -Wall -g

TARGET= ./bin/InfixaPosfixa
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/Node.o ${OBJ_DIR}/NodeStackNode.o ${OBJ_DIR}/NodeStack.o ${OBJ_DIR}/CharStackNode.o ${OBJ_DIR}/CharStack.o ${OBJ_DIR}/IntStackNode.o ${OBJ_DIR}/IntStack.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/Node.o: ${INCLUDE_DIR}/Node.hpp ${SRC_DIR}/Node.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Node.cpp -o ${OBJ_DIR}/Node.o

${OBJ_DIR}/NodeStackNode.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/NodeStackNode.hpp ${SRC_DIR}/NodeStackNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/NodeStackNode.cpp -o ${OBJ_DIR}/NodeStackNode.o

${OBJ_DIR}/NodeStack.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/NodeStackNode.hpp ${INCLUDE_DIR}/NodeStack.hpp ${SRC_DIR}/NodeStack.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/NodeStack.cpp -o ${OBJ_DIR}/NodeStack.o

${OBJ_DIR}/CharStackNode.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/CharStackNode.hpp ${SRC_DIR}/CharStackNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/CharStackNode.cpp -o ${OBJ_DIR}/CharStackNode.o

${OBJ_DIR}/CharStack.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/CharStackNode.hpp ${INCLUDE_DIR}/CharStack.hpp ${SRC_DIR}/CharStack.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/CharStack.cpp -o ${OBJ_DIR}/CharStack.o

${OBJ_DIR}/IntStackNode.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/IntStackNode.hpp ${SRC_DIR}/IntStackNode.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IntStackNode.cpp -o ${OBJ_DIR}/IntStackNode.o

${OBJ_DIR}/IntStack.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/IntStackNode.hpp ${INCLUDE_DIR}/IntStack.hpp ${SRC_DIR}/IntStack.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IntStack.cpp -o ${OBJ_DIR}/IntStack.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/Node.hpp ${INCLUDE_DIR}/NodeStackNode.hpp ${INCLUDE_DIR}/NodeStack.hpp ${INCLUDE_DIR}/CharStackNode.hpp ${INCLUDE_DIR}/CharStack.hpp ${INCLUDE_DIR}/IntStackNode.hpp ${INCLUDE_DIR}/IntStack.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

run: all
	${TARGET} ./InfixaPosfixa

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}

