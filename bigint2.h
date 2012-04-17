/*
 * bigint.h
 *
 *  Created on: 2012-4-12
 *      Author: hujin
 */

#ifndef BIGINT_H_
#define BIGINT_H_

#define BIGINT_MAX_LEN  100

typedef struct{
	int len;
	int data[BIGINT_MAX_LEN];
	int sign;//标志该数的正负
}bigint_t;

void bigint_free(bigint_t * bi);
bigint_t * bigint_new_from_string(char * str);
bigint_t * bigint_add(bigint_t * f, bigint_t * s);
bigint_t * bigint_multi(bigint_t * f, bigint_t * s);
char * bigint_to_string(bigint_t * i);
void bigint_print(bigint_t * i);

#endif /* BIGINT_H_ */
