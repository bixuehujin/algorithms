/*
 * hsort.h
 *
 *  Created on: 2012-4-20
 *      Author: hujin
 */

#ifndef HSORT_H_
#define HSORT_H_

#define HEAP_SIZE_ALLOC 100

typedef struct _heap{
	int size;
	int m_size;
	char * data;
}heap_t;

#define heap_parent(i) (i >> 1)
#define heap_left(i) (i << 1)
#define heap_right(i) ((i << 1) + 1)

heap_t * heap_new();
void heap_build_max_heap(heap_t * heap);
void heap_max_heapify(heap_t * heap , int i);
void heap_sort(heap_t * heap);
heap_t * heap_ctor(heap_t * heap);
void heap_append(heap_t * heap, char a);
void heap_ajust(heap_t * heap);
void heap_free(heap_t * heap);

#endif /* HSORT_H_ */
