CC = gcc
CFLAGS = -Wall -O0 -g -std=c99
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCES))
EXES = test_qsort test_bigint matrix power power2 heap_test
$(EXES):$(OBJS)
	$(CC) -o test_qsort test_qsort.o qsort.o
	$(CC) -o test_bigint test_bigint.o bigint2.o
	$(CC) -o power power.o
	$(CC) -o power2 power2.o
	$(CC) -o matrix matrix.o
	$(CC) -o heap_test heap_test.o hsort.o
depends:$(SOURCES)
	$(CC) -M $(SOURCES) > depends 

all:$(OBJS) $(EXES)
$(OBJS): %.o:%.c
	@echo Compiling $< to $@ ......
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXES)
.PHONY: clean
