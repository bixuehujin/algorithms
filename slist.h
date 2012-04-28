/*
 * slist.h
 *
 *  Created on: 2012-4-28
 *      Author: hujin
 */

#ifndef SLIST_H_
#define SLIST_H_

#include <malloc.h>

typedef struct _slist_node {
	struct _slist_node * next;
	char data[1];/*should always be the last element.*/
}slist_node_t;

typedef void (*slist_dtor_func_t)(void * data);
typedef int (*slist_compare_func_t)(void * , void *);
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

#define slist_appends(list,type ,salar) {\
	type tmp = salar;\
	slist_append(list, &tmp);\
}



#endif /* SLIST_H_ */
