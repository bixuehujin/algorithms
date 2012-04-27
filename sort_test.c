#include <stdio.h>
#include <string.h>
#include "qsort.h"
#include "merge_sort.h"


int main(int argc, char ** argv){
	printf("Please input a string to sort:\n");
	//printf("testing partition of given array:\n");
	char test[100] = {0};
	char tmp[100] = {0};
	scanf("%s", test);
	int len = strlen(test);
	strcpy(tmp, test);
	printf("%s\n", tmp);
	quicksort(tmp, 0, len - 1);
	printf("[quick sort] The sorted string is :%s \n", tmp);

	strcpy(tmp, test);
	printf("%s\n", tmp);
	merge_sort(tmp, len);

	printf("[merge sort] The sorted string is :%s \n", tmp);


	return 0;
}


