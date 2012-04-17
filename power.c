/*
 * power.c
 * compute the power of a number.
 *  Created on: 2012-4-12
 *      Author: hujin
 */

#include <stdio.h>
#include <sys/time.h>
/**
 * 常规方法
 */
int power1(int num, int power) {
	int ret = num, i;
	for(i = 0; i < power - 1; i ++) {
		ret *= num;
	}
	return ret;
}

/**
 * 分治法
 */
int power2(int num, int power) {
	if(power == 1) {
		return num;
	}else if(power % 2){
		return power2(num, power / 2) * num;
	}else{
		return power2(num, power / 2);
	}
}

/**
 * 减治法
 */
int power3(int num, int power) {
	if(power == 1){
		return num;
	}else{
		return power3(num, power - 1) * num;
	}
}


int calc_time(int num, int power, int(*power_func)(int, int)) {

	int i = 10000000;
	struct timeval start , end;
	gettimeofday(&start, NULL);
	while(i--) {
		(*power_func)(num, power);
	}
	gettimeofday(&end, NULL);
	return end.tv_usec - start.tv_usec;
}


int main(int argc, char **argv) {

	printf("常规方法使用时间:%d 微秒\n", calc_time(2, 30, power1));
	printf("分治方法使用时间:%d 微秒\n", calc_time(2, 30, power2));
	printf("减治方法使用时间:%d 微秒\n", calc_time(2, 30, power3));

	return 0;
}

