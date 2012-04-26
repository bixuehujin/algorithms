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

#define swap(a, b) \
{\
	char tmp;\
	tmp = a;\
	a = b;\
	b = tmp;\
}



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

/**
 * 《算法分析与设计》调整成大顶堆算法实现
 */
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

/**
 */
void heap_max_heapify(heap_t * heap , int i) {
	int left,
		right,
		largest;
	left = heap_left(i);
	right = heap_right(i);

	if(left <= heap->size && heap->data[left] > heap->data[i]) {
		largest = left;
	}else{
		largest = i;
	}

	if(right <= heap->size && heap->data[right] > heap->data[largest]) {
		largest = right;
	}

	if(largest != i) {
		swap(heap->data[i], heap->data[largest]);
		heap_max_heapify(heap, largest);
	}
}



void heap_build_max_heap(heap_t * heap) {
	int i = heap->size >> 1;
	for(;i >= 1; i --) {
		heap_max_heapify(heap, i);
	}
}


void heap_sort(heap_t * heap) {
	int i;
	heap_build_max_heap(heap);
	for(i = heap->size; i >= 2; i --) {
		swap(heap->data[i], heap->data[1]);
		heap->size -- ;
		heap_max_heapify(heap, 1);
	}
}


void heap_print(heap_t * heap) {
	printf("%s\n", heap->data + 1);
}

void heap_free(heap_t * p_heap) {
	free(p_heap->data);
	free(p_heap);
}
