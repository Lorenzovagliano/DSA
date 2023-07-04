CC=g++
CFLAGS=

TARGET= ./bin/Huffman
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/TipoNo.o ${OBJ_DIR}/ListaDinamica.o ${OBJ_DIR}/Huffman.o ${OBJ_DIR}/main.o
	${CC} ${OBJ_DIR}/*.o -o ${TARGET} ${CFLAGS}

${OBJ_DIR}/TipoNo.o: ${INCLUDE_DIR}/TipoNo.hpp ${SRC_DIR}/TipoNo.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/TipoNo.cpp -o ${OBJ_DIR}/TipoNo.o ${CFLAGS}

${OBJ_DIR}/ListaDinamica.o: ${INCLUDE_DIR}/TipoNo.hpp ${INCLUDE_DIR}/ListaDinamica.hpp ${SRC_DIR}/ListaDinamica.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ListaDinamica.cpp -o ${OBJ_DIR}/ListaDinamica.o ${CFLAGS}

${OBJ_DIR}/Huffman.o: ${INCLUDE_DIR}/ListaDinamica.hpp ${INCLUDE_DIR}/Huffman.hpp ${SRC_DIR}/Huffman.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Huffman.cpp -o ${OBJ_DIR}/Huffman.o ${CFLAGS}

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/TipoNo.hpp ${INCLUDE_DIR}/ListaDinamica.hpp ${INCLUDE_DIR}/Huffman.hpp ${SRC_DIR}/main.cpp
	${CC} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o ${CFLAGS}
	
run: all
	${TARGET}

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}
