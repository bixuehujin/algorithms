/*
 * list.h
 *
 *  Created on: 2012-5-8
 *      Author: hujin
 */

#ifndef LIST_H_
#define LIST_H_

#include "types.h"

typedef struct _list_node {
	struct _list_node * prev;
	struct _list_node * next;
	char data[0];
}list_node_t;

typedef void (*list_dtor_func_t)(pointer data);
typedef void (*list_apply_func_t)(pointer node);
typedef int (*list_compare_func_t)(pointer, pointer);

typedef struct _list{
	list_node_t * head;
	list_node_t * tail;
	int length;
	int size;
	list_dtor_func_t dtor;
	list_node_t * curr;
}list_t;


list_t * _list_new(int size, list_dtor_func_t dtor);
#define list_new(type, dtor) _list_new(sizeof(type), dtor)
bool list_append(list_t * list, pointer data);
bool list_prepend(list_t * list, pointer data);
void list_clear(list_t * list);
void list_destroy(list_t * list);

#endif /* LIST_H_ */
