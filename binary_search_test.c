/*
 * binary_search_test.c
 *
 *  Created on: 2012-4-26
 *      Author: hujin
 */

#include "binary_search.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
	char input[50] = {0};
	char e;
	printf("Please input a sequence of chars.\n");
	scanf("%s\n", input);
	printf("Pleace input a char you want to search.\n");
	e = getchar();

	printf("%s\n%d\n", input, binary_search(input, strlen(input), e));
	return 0;
}
