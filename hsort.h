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


heap_t * heap_new();

heap_t * heap_sort(heap_t * heap);

heap_t * heap_ctor(heap_t * heap);

void heap_append(heap_t * heap, char a);

void heap_ajust(heap_t * heap);

void heap_free(heap_t * heap);

#endif /* HSORT_H_ */
