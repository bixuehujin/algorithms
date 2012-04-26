/*
 * binary_search.c
 *
 *  Created on: 2012-4-26
 *      Author: hujin
 */


#include <stdio.h>
#include <string.h>

/**
 * 折半查找非递归实现，能够找到出现字符的第一个位置。
 * @param char * str 待查找的字符串
 * @param int len 待查找字符串的长度
 * @param char e 要查找的元素
 */
int binary_search(char * str, int len, char e) {
	int ret = -1,
		left = 0,
		right = len - 1,
		mid;

	while(left < right) {
		mid = left + ((right - left) >> 1);
		if(str[mid] > e) {
			right = mid - 1;
		}else if(str[mid] < e){
			left = mid + 1;
		}else{
			while(str[mid-1] == e) {
				mid --;
			}
			ret = mid;
			break;
		}
	}

	return ret;
}

