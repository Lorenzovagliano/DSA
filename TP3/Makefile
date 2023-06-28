CC=g++
CFLAGS=

TARGET= ./bin/Huffman
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/node.o ${OBJ_DIR}/list.o ${OBJ_DIR}/huff.o ${OBJ_DIR}/main.o
	${CC} ${OBJ_DIR}/*.o -o ${TARGET} ${CFLAGS}

${OBJ_DIR}/node.o: ${INCLUDE_DIR}/node.hpp ${SRC_DIR}/node.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/node.cpp -o ${OBJ_DIR}/node.o ${CFLAGS}

${OBJ_DIR}/list.o: ${INCLUDE_DIR}/node.hpp ${INCLUDE_DIR}/list.hpp ${SRC_DIR}/list.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/list.cpp -o ${OBJ_DIR}/list.o ${CFLAGS}

${OBJ_DIR}/huff.o: ${INCLUDE_DIR}/list.hpp ${INCLUDE_DIR}/huff.hpp ${SRC_DIR}/huff.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/huff.cpp -o ${OBJ_DIR}/huff.o ${CFLAGS}

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/node.hpp ${INCLUDE_DIR}/list.hpp ${INCLUDE_DIR}/huff.hpp ${SRC_DIR}/main.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o ${CFLAGS}
	
run: all
	${TARGET}

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}
