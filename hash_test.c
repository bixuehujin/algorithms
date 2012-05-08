/*
 * hash_test.c
 *
 *  Created on: 2012-5-8
 *      Author: hujin
 */

#include <stdio.h>
#include "hash_table.h"

void hash_apply_func(pointer data) {
	string tmp = (string) data;
	printf("%s\n", tmp);
}

int main(int argc, char **argv) {
	hash_table_t * table = hash_table_new(3, NULL);
	hash_table_insert(table, "hujin", sizeof("hujin"), "This is the 1nd elem in the HashTable.");
	hash_table_insert(table, "bixue", sizeof("bixue"), "This is the 2nd elem in the HashTable.");
	hash_table_insert(table, "linux", sizeof("linux"), "This is the 3nd elem in the HashTable.");
	hash_table_insert(table, "linux2", sizeof("linux2"), "This is the 4nd elem in the HashTable.");
	string str = (string) hash_table_find(table, "hujin", sizeof("hujin"));
	if(str) {
		printf("%s\n", str);
	}else{
		printf("find error\n");
	}
	str = (string)hash_table_find(table ,"linux2", sizeof("linux2"));
	if(str) {
		printf("%s\n", str);
	}else{
		printf("find error\n");
	}

	hash_table_apply(table, (hash_table_apply_func_t) hash_apply_func, true);


	return 0;
}

