all: geraarvbin

geraarvbin:
	gcc -o bin/geraarvbin src/geraarvbin.c -lm

run: all
	./bin/geraarvbin -o tree.txt -s 1 -n 7

clean:
	rm -f bin/**