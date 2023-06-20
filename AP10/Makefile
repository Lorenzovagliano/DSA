CC=gcc
CFLAGS=-Wall

TARGET= ./bin/arvB
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/arvB.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/arvB.o: ${SRC_DIR}/arvB.c
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/arvB.c -o ${OBJ_DIR}/arvB.o

run: all
	${TARGET} ./arvB

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}

