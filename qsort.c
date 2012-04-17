#include <stdio.h>

#define swap(e1, e2) {\
		char tmp;\
		tmp = e1;\
		e1 = e2;\
		e2 = tmp;\
	}

int partition(char input[], int l, int r){
	char p = input[l];
	int i = l, j = r + 1;
	do{
		do{
			i++;
		}while(input[i] < p);

		do{
			j--;
		}while(input[j] > p);

		swap(input[i], input[j]);
	}while(j > i);

	swap(input[i], input[j]);
	swap(input[j], input[l]);

	return j;
}



void quicksort(char input[], int l, int r){
	//partition(input, l, r);
	if (l < r){
		int p;
		p = partition(input, l, r);

		quicksort(input, l, p-1);
		quicksort(input, p+1, r);
	}
}

