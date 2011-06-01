/*
 * statics_test.c
 *
 *  Created on: 2012-5-30
 *      Author: hujin
 */

#include <stdio.h>
#include "statics.h"


int main(int argc, char **argv) {
	//0 2 4 5 8 9 10 23
	int arr[8] = {9, 2 ,4 ,5, 8, 10, 0, 23};
	int select_index = 5;
	int index = quick_select(arr, 8, select_index);
	printf("the %dth index of array is %d\n", select_index, arr[index]);
	return 0;
}


