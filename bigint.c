/*
 * bigint.c
 *
 *  Created on: 2012-4-12
 *      Author: hujin
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "bigint.h"
#include <stdlib.h>

int8_t ctoi8(char c){
	return c - '0';
}

char i8toc(int8_t u) {
	return u + '0';
}

/*
bigint_t *bigint_new(){
	bigint_t *ret = malloc(sizeof(bigint_t));
	ret->data = NULL;
	ret->len = 0;
	return ret;
}

void bigint_alloc(bigint_t * p_int, int len) {
	p_int->len = len;
	p_int->data = malloc(sizeof(int8_t) * len);
}

void bigint_destroy(bigint_t * p_int) {
	if(p_int == NULL) return;
	if(p_int->data != NULL) {
		free(p_int->data);
	}
	free(p_int);
}

*/

void bigint_assign(bigint_t * p_int, char * in) {
	int i, len;
	len = strlen(in);
	for(i = len; i>0; i--) {
		p_int->data[len - i] = ctoi8(in[i - 1]);
	}
	p_int->len = len;
}

void bigint_devide(bigint_t orgin, bigint_t * o1, bigint_t * o0) {

	int i, new_len;
	new_len = orgin.len / 2;
	o1->len = o0->len = new_len;

	for(i=0; i < new_len; i++){
		o0->data[i] = orgin.data[i];
	}

	for(i = new_len; i < orgin.len; i++){
		o1->data[i - new_len] = orgin.data[i];;
	}
}

void bigint_plus(bigint_t a, bigint_t b, bigint_t *ret) {
	int i, max_len;
	max_len = a.len > b.len ? a.len : b.len;
	for(i=0; i< max_len ; i++){
		ret->data[i] = a.data[i] + b.data[i];
	}
	ret->len = max_len;
}

void bigint_milus(bigint_t a, bigint_t b, bigint_t *ret) {
	int i, max_len;
	max_len = a.len > b.len ? a.len : b.len;
	for(i=0; i< max_len ; i++){
		ret->data[i] = a.data[i] - b.data[i];
	}
	ret->len = max_len;
}

void bigint_move(bigint_t * integer, int n){
	int i;
	for(i = integer->len - 1; i>=0; i --){
		integer->data[i + n] = integer->data[i];
	}
	for(i=n - 1; i>=0; i--) {
		integer->data[i] = 0;
	}
	integer->len += n;
}

void bigint_multiplication(bigint_t a, bigint_t b, bigint_t * ret) {
	bigint_t a1={0}, a0={0}, b1={0}, b0={0}, c2, c1, c0, tmp1, tmp2;
	if(a.len > 1 && a.len == b.len) {
		bigint_devide(a, &a1, &a0);
		bigint_devide(b, &b1, &b0);
		bigint_multiplication(a1, b1, &c2);
		bigint_multiplication(a0, b0, &c0);

		bigint_plus(a1, a0, &tmp1);
		bigint_plus(b1, b0, &tmp2);
		bigint_multiplication(tmp1, tmp2, &c1);

		bigint_plus(c2, c0, &tmp1);
		bigint_milus(c1, tmp1, &c1);

		bigint_move(&c2, a.len);
		bigint_move(&c1, a.len / 2);
		bigint_plus(c2, c1, ret);
		bigint_plus(*ret, c0, ret);

	}else{
		bigint_plus(a, b, ret);
	}
}


void bigint_to_string(bigint_t integer, char output[]) {
	int i;
	for(i=0; i<integer.len; i++) {
		printf("%d\n", integer.data[i]);
		output[i] = i8toc(integer.data[i]);
	}
	output[i] = '\0';
}


void bigint_print(bigint_t integer, char * text) {
	char output[BIGINT_MAX_LEN];
	bigint_to_string(integer, output);
	printf("\n%s -- string: %s len:%d\n",text, output, integer.len);
}
