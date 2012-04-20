#include <stdio.h>
#include <time.h>

int Power_1(int a, int n) {
	int p = a;
	while(--n){
		p = p * a;
	}
	return p;
}

int Power_2(int a, int n) {
	if(n == 1) return a;

	int t;
	t = Power_2(a, n / 2);
	if(n % 2 == 0){
		return t * t;
	}else{
		return t * t * a;
	}
}

int Power_3(int a, int n) {
	if(n == 1) {
		return a;
	}else{
		return a *  Power_3(a, n - 1);
	}
}

int main(int arvc, char **argv) {

	int b = Power_2(2, 30);
	int c = Power_3(2, 30);

	clock_t start , finish;


	int i = 1000000;
	start = clock();
	while(i--) {
		Power_1(2, 30);
	}
	finish = clock();
	printf("power1: using %ld \n", finish - start);
	//--------------------------------
	i = 1000000;
	start = clock();
	while(i--) {
		Power_2(2, 30);
	}
	finish = clock();
	printf("power1: using %ld \n", finish - start);

	//--------------------------------
	i = 1000000;
	start = clock();
	while(i--) {
		Power_3(2, 30);
	}
	finish = clock();
	printf("power1: using %ld \n", finish - start);


	return 0;
}
