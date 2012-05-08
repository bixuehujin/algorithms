/*
 * list_test.c
 *
 *  Created on: 2012-5-8
 *      Author: hujin
 */

#include <stdio.h>

#include "list.h"
typedef struct _record{
	int id;
	char url[200];
}record;

int record_compare_func(pointer r1, pointer r2) {
	record * rr1 = (record *)r1;
	record * rr2 = (record *)r2;
	if(rr1->id > rr2->id) {
		return 1;
	}else if(rr1->id < rr2->id) {
		return -1;
	}else{
		return 0;
	}
}

void record_print(pointer data) {
	record * r = (record *)data;
	printf("%d: %s\n", r->id, r->url);
}

int main(int argc, char **argv) {
	list_t * list = list_new(record, NULL);
	record re1 = {1, "www.baidu.com"};
	list_append(list, &re1);

	record re3 = {3, "www.sohu.com"};
	list_append(list, &re3);

	record re5 = {5, "www.sina.com"};
	list_append(list, &re5);

	record re4 = {4, "www.163.com"};
	//list_insert(list, &re3, &re4,(list_compare_func_t) record_compare_func);


	record ren = {10, "www.163.com"};
	list_insert(list, &ren, &re4,(list_compare_func_t) record_compare_func);

	list_apply(list, (list_apply_func_t) record_print);

	return 0;
}
