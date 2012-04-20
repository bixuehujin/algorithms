/*
 * heap_test.c
 *
 *  Created on: 2012-4-20
 *      Author: hujin
 */
#include "hsort.h"


int main(int argc, char **argv) {
	heap_t * heap = heap_new();
	heap_append(heap, '5');
	heap_appends(heap, "87202");
	heap_print(heap);
	heap_ajust(heap);
	heap_print(heap);
	heap_free(heap);
	return 0;
}


