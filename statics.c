/*
 * statics.c
 * some algorithms resolve order statistics problems.
 *
 *  Created on: 2012-5-30
 *      Author: hujin
 */

#include <stdio.h>

#define swap(a, b) {\
	tmp = a;\
	a = b;\
	b = tmp;}\

/**
 *
 */
int quick_partition(int arr[], int l, int r) {
	int i = l -  1, j = l;
	int p = arr[r], tmp;
	for(; j < r; j ++) {
		if(arr[j] < p) {
			i ++;
			swap(arr[i], arr[j]);
		}
	}
	i ++;
	swap(arr[i], arr[r]);
	return i;
}


int _quick_select(int input[], int l, int r, int i) {

	if(l == r) {
		return l;
	}
	int p = quick_partition(input, l, r);
	int k = p - l + 1;
	if(i < k) {
		return _quick_select(input, l, p - 1, i);
	}else if(i == k) {
		return p;
	}else {
		return _quick_select(input, p + 1 , r, i - k);
	}
}

/**
 * find the kth smallest element in a given array .
 * @param int input[] The given array
 * @param int l		  The lenght of given array
 * @param int select_index
 */
int quick_select(int input[], int len, int select_index) {
	return _quick_select(input, 0, len - 1, select_index);
}
