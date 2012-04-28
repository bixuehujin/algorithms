/*
 * bigint.h
 *
 *  Created on: 2012-4-12
 *      Author: hujin
 */

#ifndef BIGINT_H_
#define BIGINT_H_
#include <sys/types.h>

#define BIGINT_MAX_LEN  100

typedef struct{
	int len;
	int8_t  data[BIGINT_MAX_LEN];
}bigint_t;

int8_t ctoi8(char c);

void bigint_assign(bigint_t *  p_int, char * in);

void bigint_multiplication(bigint_t a, bigint_t b, bigint_t * ret);

void bigint_to_string(bigint_t integer, char output[]);
void bigint_print(bigint_t integer, char * text) ;
#endif /* BIGINT_H_ */
