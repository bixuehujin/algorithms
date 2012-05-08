/*
 * list.c
 *
 *  Created on: 2012-5-8
 *      Author: hujin
 */

#include <stdio.h>
#include "list.h"


list_t * _list_new(int size, list_dtor_func_t dtor) {
	list_t * ret = malloc(sizeof(list_t));
	if(!ret) return NULL;

	ret->curr = NULL;
	ret->dtor = dtor;
	ret->size = size + sizeof(list_t);
	ret->head = NULL;
	ret->tail = NULL;
	ret->length = 0;
	return ret;
}

void list_append(list_t * list, pointer data) {
	list_node_t * node = malloc(list->size);
	node->next = NULL;
	node->prev = list->tail;
	memcpy(node->data, data, list->size);

	if(!list->head) {
		list->head = list->tail = node;
	}

	list->tail = node;
}


void list_prepend(list_t * list, pointer data) {
	list_node_t * node = malloc(list->size);
	node->prev = NULL;
	node->next = list->head;
	memcpy(node->data, data, list->size);

	if(!list->head) {
		list->head = list->tail = node;
	}
	list->head = node;
}

