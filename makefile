CC = gcc
BUILD_PATH=build
CFLAGS = -Wall -O0 -g -std=c99
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCES))
EXES = sort_test test_bigint matrix power power2 heap_test binary_search_test string_test slist_test
$(EXES):$(OBJS)
	$(CC) -o sort_test sort_test.o qsort.o merge_sort.o
	$(CC) -o test_bigint test_bigint.o bigint2.o
	$(CC) -o power power.o
	$(CC) -o power2 power2.o
	$(CC) -o matrix matrix.o
	$(CC) -o heap_test heap_test.o hsort.o
	$(CC) -o binary_search_test binary_search.o binary_search_test.o
	$(CC) -o string_test string_test.o bitmap.o strings.o
	$(CC) -o slist_test slist_test.o slist.o
	
depends:$(SOURCES)
	$(CC) -M $(SOURCES) > depends 

all:$(OBJS) $(EXES)
$(OBJS): %.o:%.c
	@echo Compiling $< to $@ ......
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f  $(EXES)
	find . -name \*.o | xargs rm -f
.PHONY: clean
