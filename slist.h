/*
 * slist.h
 *
 *  Created on: 2012-4-28
 *      Author: hujin
 */

#ifndef SLIST_H_
#define SLIST_H_

#include <string.h>
#include <malloc.h>

typedef struct _slist_node {
	struct _slist_node * next;
	char data[0];/*Needs to always be the last in the struct.*/
}slist_node_t;

typedef void (*slist_dtor_func_t)(void * data);
typedef int (*slist_compare_func_t)(slist_node_t * , slist_node_t *);
typedef void (*slist_apply_func_t)(void *);

typedef struct _slist{
	slist_node_t * head;
	slist_node_t * tail;
	int length;
	int size;
	slist_dtor_func_t dtor;
	slist_node_t * curr;
}slist_t;

#define slist_new(type, dtor) _slist_new(sizeof(type), dtor)

#define slist_destroy(pslist) slist_clear(pslist);\
	free(pslist);\
	pslist = NULL;

slist_t * _slist_new(int size, slist_dtor_func_t dtor);
void slist_apply(slist_t * list, slist_apply_func_t apply_func);
int slist_append(slist_t * list, void * data);
int slist_prepend(slist_t * list, void * data);
void slist_clear(slist_t * list);

#define slist_append_ex(list, type ,salar) {\
	type tmp = salar;\
	slist_append(list, &tmp);\
}

#define slist_appendi(list, integer)    slist_append_ex(list, int, integer)
#define slist_appendl(list, longval)    slist_append_ex(list, long, longval)
#define slist_appendf(list, floatval)   slist_append_ex(list, float, floatval)
#define slist_appendd(list, doubleval)  slist_append_ex(list, double, doubleval)

#define slist_appends(list, str) {\
	char * tmp = strdup(str);\
	slist_append(list, &tmp);\
}


#endif /* SLIST_H_ */
