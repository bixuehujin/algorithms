CC = gcc
BUILD_PATH=build 
vpath %.h include   
INCLUDE = -I/usr/include -Iinclude
CFLAGS = -Wall -O0 -g -std=c99 $(INCLUDE)
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCES))
EXES = sort_test test_bigint matrix power power2 heap_test binary_search_test string_test slist_test \
statics_test
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
	$(CC) -o list_test list_test.o list.o
	$(CC) -o hash_test hash_test.o hash_table.o
	$(CC) -o statics_test statics_test.o statics.o
#include $(subst .c,.d,$(SOURCES))
	
#%.d:%.c
#	$(CC) -M  $(INCLUDE) $<  > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
	 
	


all: $(EXES)
%.o:%.c
	@echo Compiling $< to $@ ......
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f  $(EXES)
	find . -name '*.[od]' | xargs rm -f
.PHONY: clean
