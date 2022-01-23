
CC=gcc
CFLAGS=-Wall -Wextra -O3 -pedantic
TEST_CFLAGS=-Wall -Wextra -pedantic -Isrc/
RELEASE=release
TARGET=liblist


all: prepare list.o
	 ar rcs $(RELEASE)/$(TARGET).a *.o 


install:
	cp -v $(RELEASE)/$(TARGET).a /usr/lib
	cp -v src/list.h /usr/include


list.o: src/list.c src/list.h
	$(CC) $(CFLAGS) -c src/list.c -o list.o
	

test: prepare test.o list.o
	$(CC) $(TEST_CFLAGS) test.o list.o -o $(RELEASE)/test
	$(RELEASE)/test

struct.o: test/struct.h test/struct.c
	$(CC) $(TEST_CFLAGS) -c test/struct.c -o struct.o

test.o: test/test.c
	$(CC) $(TEST_CFLAGS) -c test/test.c -o test.o


prepare:
	mkdir -pv $(RELEASE)


clean:
	rm -frv $(RELEASE)
	rm -vf *.o
