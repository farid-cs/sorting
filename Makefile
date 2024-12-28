CC = cc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
OBJECTS = tests.o sort.o

all: tests

tests: ${OBJECTS}
	${CC} -o $@ ${OBJECTS}

test: tests
	./tests

clean:
	rm -f tests *.o

.PHONY: all test clean
