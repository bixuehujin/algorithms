#include <stdio.h>

#define swap(e1, e2) {\
		char tmp;\
		tmp = e1;\
		e1 = e2;\
		e2 = tmp;\
	}

/**
 * 该版本不好
 */
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

/**
 * 双向扫描进行分区
 */
int partition2(char input[], int left, int right) {
	int l, r;
	l = left, r = right;
	char p = input[left];
	while(l < r) {
		// 条件应该 为 l < r 否则会出现过多的交换
		while(l < r && input[r] >= p) {
			r --;
		}
		input[l] = input[r];
		while(l < r && input[l] <= p) {
			l ++;
		}
		input[r] = input[l];
	}
	input[l] = p;
	return l;
}

/**
 * 算法导论分区实现
 */
int partition3(char input[], int left, int right) {
	// j 作为开路先锋，找寻比小于等于 pivot 的元素，然后再与 i 进行交换，却表 i 坐在元素比 pivot 小
	int i = left -1,  j;
	char p = input[right];

	for(j = left; j < right; j ++) {
		if(input[j] <= p) {
			i ++;
			swap(input[i], input[j]);
		}
	}
	swap(input[i + 1], input[right]);
	return i + 1;
}

void quicksort(char input[], int l, int r){
	//partition(input, l, r);
	if (l < r){
		int p;
		p = partition3(input, l, r);
		quicksort(input, l, p-1);
		quicksort(input, p+1, r);
	}
}

