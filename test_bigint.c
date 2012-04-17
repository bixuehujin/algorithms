/*
 * test_bigint.c
 *
 *  Created on: 2012-4-12
 *      Author: hujin
 */
#include <stdio.h>
#include "bigint2.h"

int main(int argc, char **argv) {

	char input1[100] = {0};
	char input2[100] = {0};
	printf("Please input the first number:\n");
	scanf("%s", input1);
	printf("Please input the second number:\n");
	scanf("%s", input2);
	bigint_t * bi = bigint_new_from_string(input1);

	bigint_t * bi2 = bigint_new_from_string(input2);
	bigint_t * product = bigint_multi(bi, bi2);
	char * output = bigint_to_string(product);
	bigint_print(product);
	printf("The product is of %s and %s is:%s\n",input1, input2, output);
	free(output);

	bigint_free(bi);
	bigint_free(bi2);
	bigint_free(product);

	return 0;
}
