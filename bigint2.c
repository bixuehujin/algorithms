/*
 * bigint.c
 *
 *  Created on: 2012-4-12
 *      Author: hujin
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "bigint2.h"
#include <stdlib.h>


bigint_t * bigint_new() {
	bigint_t * ret = (bigint_t *) malloc(sizeof(bigint_t));
	if(ret == NULL) return NULL;
	memset(ret, 0, sizeof(bigint_t));
	return ret;
}


bigint_t * bigint_new_from_string(char * str){
	bigint_t * ret = (bigint_t *) malloc(sizeof(bigint_t));
	if(ret == NULL) return NULL;
	memset(ret, 0, sizeof(bigint_t));

	int pos = 1, i;
	if(str[0] == '-'){
		ret->sign = -1;
	}else if(str[0] == '+') {
		ret->sign = 1;
	}else{
		ret->sign = 1;
		pos = 0;
	}
	int len = strlen(str);
	int j = 0;
	for(i = len - 1; i >= pos; i--, j++){
		ret->data[j] = str[i] - '0';
	}
	ret->len = len;
	return ret;
}


int bigint_cmp_ob(bigint_t f, bigint_t s) {
	int i;
	if(f.len > s.len){
		return 1;
	}else if(f.len < s.len) {
		return -1;
	}else{
		for(i=0; i < f.len; i++) {
			if(f.data[i] > s.data[i]) {
				return 1;
			}else if(f.data[i] < s.data[i]) {
				return -1;
			}
		}
		return 0;
	}
}

bigint_t * bigint_add(bigint_t * a, bigint_t * b) {

	bigint_t * ret = bigint_new();//make an empty bigint.
	if(!ret) return NULL;
	/*
	if(a->sign * b->sign > 0) {
		ret->sign = a->sign;
	}else{

	}
	*/
	int i;
	int max = a->len > b->len ? a->len : b->len;
	for(i = 0; i < max; i ++) {
		ret->data[i] = a->data[i] + b->data[i];
	}
	ret->len = i;

	return ret;
}


void bigint_print(bigint_t * bi){
	if(bi->sign < 0){
		putchar('-');
	}
	int i;
	int * data = bi->data;
	for(i=0; data[i] != 0 || i < bi->len; i++) {
		if(data[i] > 10) {
			data[i + 1] += data[i] / 10;
			data[i] = data[i] % 10;
		}
	}
	bi->len = i;
	for(i = bi->len - 1; i >= 0; i--) {
		printf("%d", data[i]);
	}
	printf("\n");
}




bigint_t * bigint_multi(bigint_t * f, bigint_t * s){
	bigint_t * ret = bigint_new();
	if(ret == NULL) return NULL;

	int i, j;
	for(i = 0; i < s->len; i ++) {
		for(j = 0; j < f->len; j ++) {
			ret->data[i + j] += f->data[j] * s->data[i];
			//printf("%d * %d -- %d:%d",f->data[j], s->data[i], i, j);
 		}
		//printf("\n");
	}
	ret->len = i + j - 1;
	return ret;
}

char * bigint_to_string(bigint_t * bi) {
	int i, j, is_neg;
	int * data = bi->data;
	for(i=0; data[i] != 0 || i < bi->len; i++) {
		if(data[i] > 10) {
			data[i + 1] += data[i] / 10;
			data[i] = data[i] % 10;
		}
	}
	bi->len = i;
	if(bi->sign < 0) {
		is_neg = 1;
	}else{
		is_neg = 0;
	}

	char * ret = malloc(sizeof(char) * (bi->len + is_neg));

	for(i = bi->len - 1, j = 0; i >= 0; i--, j ++) {
		 ret[i + is_neg] = data[j] + '0';
	}
	if(is_neg) {
		ret[0] = '-';
	}
	return ret;
}

void bigint_free(bigint_t * bi) {
	free(bi);
}
