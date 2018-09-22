CC = gcc

all: testing build

testing:
	$(CC) -DAC_TESTING main.c module1.c -o comp-test

build:	
	$(CC) main.c module1.c -o comp-reg

.PHONY: clean
clean:
	rm -f comp-test comp-reg
