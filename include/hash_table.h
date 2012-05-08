/*
 * hashtable.h
 *
 *  Created on: 2012-5-8
 *      Author: hujin
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_
#include "types.h"

typedef void (*hash_table_dtor_func_t)(pointer data);
typedef void (*hash_table_apply_func_t)(pointer data);

typedef struct _hash_bucket{
	ulong idx;
	uint key_size;
	pointer data;
	struct _hash_bucket * next;
	struct _hash_bucket * elem_next;
	struct _hash_bucket * elem_prev;
	char key[0];
}hash_bucket_t;

typedef struct _hash_table{
	int size;
	int bucket_size;
	hash_bucket_t ** bucket;
	hash_bucket_t * head;
	hash_bucket_t * tail;
	hash_bucket_t * curr;
	hash_table_dtor_func_t dtor;
}hash_table_t;


hash_table_t * hash_table_new(int size, hash_table_dtor_func_t dtor);
void hash_table_clear(hash_table_t * ht);
void hash_table_destroy(hash_table_t * ht);
void hash_table_rehash(hash_table_t * ht);
bool hash_table_insert(hash_table_t * ht, string key, int key_len, pointer data);
bool hash_table_remove(hash_table_t * ht, string key, int key_len);
pointer hash_table_find(hash_table_t * ht, string key, uint key_size);
void hash_table_apply(hash_table_t * ht, hash_table_apply_func_t func, bool reverse);

#endif /* HASH_TABLE_H_ */
