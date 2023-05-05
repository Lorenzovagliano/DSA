CC=g++
CFLAGS=-std=c++11 -Wall -g

TARGET= ./bin/InfixaPosfixa
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/TipoNo.o ${OBJ_DIR}/Pilha.o ${OBJ_DIR}/ArvoreBinaria.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/TipoNo.o: ${INCLUDE_DIR}/TipoNo.hpp ${SRC_DIR}/TipoNo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/TipoNo.cpp -o ${OBJ_DIR}/TipoNo.o

${OBJ_DIR}/Pilha.o: ${INCLUDE_DIR}/TipoNo.hpp ${INCLUDE_DIR}/Pilha.hpp ${SRC_DIR}/Pilha.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Pilha.cpp -o ${OBJ_DIR}/Pilha.o

${OBJ_DIR}/ArvoreBinaria.o: ${INCLUDE_DIR}/TipoNo.hpp ${INCLUDE_DIR}/Pilha.hpp ${INCLUDE_DIR}/ArvoreBinaria.hpp ${SRC_DIR}/ArvoreBinaria.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ArvoreBinaria.cpp -o ${OBJ_DIR}/ArvoreBinaria.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/TipoNo.hpp ${INCLUDE_DIR}/Pilha.hpp ${INCLUDE_DIR}/ArvoreBinaria.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

run: all
	${TARGET} ./InfixaPosfixa

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}

