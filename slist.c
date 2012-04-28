/*
 * slist.c
 *
 *  Created on: 2012-4-28
 *      Author: hujin
 */

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "types.h"
#include "slist.h"


slist_t * _slist_new(int size, slist_dtor_func_t dtor) {
	slist_t * ret = malloc(sizeof(slist_t));
	assert(ret != NULL);
	if(ret == NULL) return NULL;

	ret->curr = NULL;
	ret->dtor = dtor;
	ret->head = NULL;
	ret->tail = NULL;
	ret->length = 0;
	ret->size = size;

	return ret;
}



int slist_append(slist_t * list, pointer data) {
	slist_node_t * tmp = malloc(sizeof(slist_node_t) + list->size);
	if(!tmp) return 0;

	tmp->next = NULL;
	memcpy(tmp->data, data, list->size);

	if(list->tail) {
		list->tail->next = tmp;
	}else{
		list->head = tmp;
		list->tail = tmp;
	}
	list->tail = tmp;
	list->length ++;

	return 1;
}



int slist_prepend(slist_t * list, pointer data) {
	slist_node_t * tmp = malloc(sizeof(slist_node_t) + list->size);
	if(!tmp) return 0;

	tmp->next = list->head;
	memcpy(tmp->data, data, list->size);

	if(!list->tail) {
		list->tail = tmp;
	}

	list->head = tmp;
	list->length ++;
	return 1;
}


void slist_apply(slist_t * list, slist_apply_func_t apply_func) {
	slist_node_t * elem;
	for(elem = list->head; elem; elem = elem->next) {
		apply_func(elem->data);
	}
}

void slist_clear(slist_t * list) {
	slist_node_t * curr = list->head, *next;
	while(curr) {
		next = curr->next;
		if(list->dtor) {
			list->dtor(curr->data);
		}
		free(curr);
		curr = next;
	}
	list->head = list->tail = NULL;
	list->length = 0;
}


void slist_string_dtor_func(pointer data) {
	string * d = (string *)data;
	free(*d);
}







