/*
 * slist_test.c
 *
 *  Created on: 2012-4-28
 *      Author: hujin
 */

#include <stdio.h>
#include <string.h>
#include "slist.h"

void slist_print(pointer data) {
	printf("%s\n", *(string *)data);
}


int main(int argc, char **argv) {
	slist_t * slist = slist_new(string, slist_string_dtor_func);

	slist_appends(slist, "hujin");
	slist_appends(slist, "bixue");
	slist_appends(slist, "11111");
	slist_appends(slist, "22222");
	slist_appends(slist, "33333");
	slist_appends(slist, "44444");
	slist_apply(slist, (slist_apply_func_t)slist_print);
	printf("\n");
	slist_reverse(slist);
	slist_apply(slist, (slist_apply_func_t)slist_print);
	slist_destroy(slist);
	return 0;
}

