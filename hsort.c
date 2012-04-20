/*
 * hsort.c
 *
 *  Created on: 2012-4-20
 *      Author: hujin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hsort.h"

heap_t * heap_new() {
	heap_t * ret = malloc(sizeof(heap_t));
	ret->size = 0;
	ret->m_size = HEAP_SIZE_ALLOC;
	ret->data = malloc(sizeof(char) * HEAP_SIZE_ALLOC);
	memset(ret->data, 0, sizeof(char) * HEAP_SIZE_ALLOC);
	return ret;
}


void heap_append(heap_t * heap, char c) {
	if(heap->size == heap->m_size) {
		heap->data = realloc(heap->data, sizeof(char) * (heap->m_size + HEAP_SIZE_ALLOC));
	}
	heap->data[heap->size + 1] = c;
	heap->size ++ ;
}

void heap_appends(heap_t * heap, char * str) {
	int i=0;
	while(str[i] != '\0') {
		heap->data[heap->size + 1] = str[i];
		heap->size ++;
		i ++;
	}
}


void heap_ajust(heap_t * heap) {
	int k;
	int is_heap;
	char v;
	int j;
	for(int i = heap->size / 2; i > 0; i --) {
		k = i;
		v = heap->data[k];
		is_heap = 0;
		while(!is_heap && 2 * k <= heap->size) {
			j = 2 * k;
			if(j < heap->size) {
				if(heap->data[j] < heap->data[j + 1]) {
					j ++;
				}
			}
			if(v >= heap->data[j]) {
				is_heap = 1;
			}else{
				heap->data[k] = heap->data[j];
				k = j;
			}
		}
	}
	heap->data[k] = v;
}

void heap_print(heap_t * heap) {
	printf("%s\n", heap->data + 1);
}

void heap_free(heap_t * p_heap) {
	free(p_heap->data);
	free(p_heap);
}
