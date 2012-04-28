/*
 * string_test.c
 *
 *  Created on: 2012-4-26
 *      Author: hujin
 */

#include "strings.h"
#include <stdio.h>


int main(int argc, char **argv) {
	char a[] ="qwerty";
	char b[] = "ert";
	char c[] = "kijd";
	if(string_has_chars_of(a, b)) {
		printf("string \"%s\" contains chars of \"%s\".\n", a, b);
	}else{
		printf("string \"%s\" do not contains chars of \"%s\".\n", a, b);
	}

	if(string_has_chars_of(a, c)) {
		printf("string \"%s\" contains chars of \"%s\".\n", a, c);
	}else{
		printf("string \"%s\" do not contains chars of \"%s\".\n", a, c);
	}
	return 0;
}


