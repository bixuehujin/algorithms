#include <stdio.h>
#include <string.h>
#include "qsort.h"

int main(int argc, char ** argv){
	printf("Please input a string to sort:\n");
	//printf("testing partition of given array:\n");
	char test[100] = {0};
	scanf("%s", test);
	int len = strlen(test);
	//int p = partition(test, 0, p);
	//printf("The partition element is at position: %d\n", len);
	quicksort(test, 0, len - 1);
	printf("The sorted string is :%s \n", test);
	return 0;
}


