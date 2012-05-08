/*
 * list.c
 *
 *  Created on: 2012-5-8
 *      Author: hujin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


list_t * _list_new(int size, list_dtor_func_t dtor) {
	list_t * ret =(list_t *) malloc(sizeof(list_t));
	if(!ret) return NULL;

	ret->curr = NULL;
	ret->dtor = dtor;
	ret->size = size;
	ret->head = NULL;
	ret->tail = NULL;
	ret->length = 0;
	return ret;
}

bool list_append(list_t * list, pointer data) {
	list_node_t * node = (list_node_t *) malloc(list->size + sizeof(list_node_t));
	if(!node) return false;

	node->next = NULL;
	node->prev = list->tail;
	memcpy(node->data, data, list->size);

	if(!list->head) {
		list->head = list->tail = node;
	}else{
		list->tail->next = node;
	}

	list->tail = node;

	list->length ++;
	return true;
}


bool list_prepend(list_t * list, pointer data) {
	list_node_t * node = (list_node_t *) malloc(list->size + sizeof(list_node_t));
	if(!node) return false;

	node->prev = NULL;
	node->next = list->head;
	memcpy(node->data, data, list->size);

	if(!list->head) {
		list->head = list->tail = node;
	}
	list->head = node;

	list->length ++;
	return true;
}

void list_clear(list_t * list) {
	list_node_t *curr = list->head, *next;
	while(curr) {
		if(list->dtor) {
			list->dtor(curr->data);
		}
		next = curr->next;
		free(curr);
		curr = next;
	}
	list->head = list->tail = NULL;
	list->length = 0;
}

/**
 * insert the a element after the specified element.
 * @param list_t * list the linked list you want to insert.
 * @param pointer position
 * @param pointer data;
 * @param list_compare_func_t func
 */
bool list_insert(list_t * list,pointer position, pointer data, list_compare_func_t func) {
	list_node_t * curr = list->head;
	list_node_t * node  = (list_node_t *)malloc(list->size + sizeof(list_node_t));
	if(!node) return false;

	while(curr) {
		if(func && func(position, curr->data) == 0) {
			break;
		}
		curr = curr->next;
	}

	if(curr) {
		memcpy(node->data, data, list->size);
		node->next = curr->next;
		node->prev = curr;

		curr->next = node;
	}else{
		list_append(list, data);
	}

	return true;
}



void list_apply(list_t * list, list_apply_func_t func) {
	list_node_t * curr = list->head;
	while(curr) {
		func(curr->data);
		curr = curr->next;
	}
}
