/*
 * merge_sort.c
 *
 *  Created on: 2012-4-27
 *      Author: hujin
 */


#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define swap(a, b) \
{ \
	char tmp;\
	tmp = a;\
	a = b;\
	b = tmp;\
}

void merge(char * arr, int start,int mid, int end) {
	if(end - start == 1) {
		if (arr[start] > arr[end]) {
			swap(arr[start], arr[end]);
		}
	}else {
		int len = end - start + 1; //NOTICE: The len should be end - start + 1 .
		char * tmp = malloc(sizeof(char) * len);
		int i = start, j = mid + 1, k = 0;
		while(i <= mid && j <= end) {
			if(arr[i] < arr[j]) {
				tmp[k++] = arr[i++];
			}else{
				tmp[k++] = arr[j++];
			}
		}

		while(i <= mid) {
			tmp[k++] = arr[i++];
		}

		while(j <= end) {
			tmp[k++] = arr[j++];
		}

		for(k = start, i=0; i < len; i ++, k ++) {
			arr[k] = tmp[i];
		}

		free(tmp);
	}
}

void _merge_sort(char * arr, int start, int end) {
	if(start < end) {
		int mid = start + ((end - start) >> 1);
		_merge_sort(arr, start, mid);
		_merge_sort(arr, mid + 1, end);
		merge(arr, start,mid,end);
	}
}


void merge_sort(char * arr, int len) {
	if(len < 0) {
		len = strlen(arr);
	}
	_merge_sort(arr, 0 , len - 1);
}

