/*
 * slist_test.c
 *
 *  Created on: 2012-4-28
 *      Author: hujin
 */

#include <stdio.h>
#include "slist.h"
void slist_print(void * data) {
	printf("%d\n", *(int *)data);
}
int main(int argc, char **argv) {
	slist_t * slist = slist_new(int, NULL);

	slist_appends(slist, int, 23);
	slist_appends(slist, int, 34);

	slist_apply(slist, slist_print);

	slist_destroy(slist);
	return 0;
}

