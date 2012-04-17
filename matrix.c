
/**
 * 矩阵乘法分治算法实现，仅支持2^n的矩阵乘法。
 */

#include <stdio.h>
#include <stdlib.h>
#define MATRIX_MAX_DIMENSION 32

#define matrix_for_init {{{0},{0}},0}

typedef struct{
	int data[MATRIX_MAX_DIMENSION][MATRIX_MAX_DIMENSION];
	int dimension;
}matrix_t;


/**
 * indicate whether a number is the power of 2.
 * @param int n The input number n.
 * @return int 1 or 0
 */
int is_power_of_2(int n) {
	if(n && !(n & (n - 1))){
		return 1;
	}else{
		return 0;
	}
}

void matrix_input(matrix_t *m1){
	printf("The dimension(should be the power of 2):");
	scanf("%d", &m1->dimension);

	if(m1->dimension > MATRIX_MAX_DIMENSION) {
		printf("error: the max dimension should be %d.\n", MATRIX_MAX_DIMENSION);
		exit(-1);
	}

	if(!is_power_of_2(m1->dimension)) {
		printf("error: the dimension of matrix should the power of 2.\n");
		exit(-1);
	}

	printf("The sequence of %d numbers:", m1->dimension * m1->dimension);
	int i, j;
	for(i=0;i < m1->dimension ; i ++){
		for(j=0; j < m1->dimension; j ++){
			scanf("%d", &m1->data[i][j]);
		}
	}
}

int matrix_add(matrix_t m1, matrix_t m2, matrix_t *ret){
	if(m1.dimension != m2.dimension) {
		printf("error: the dimension do not match!\n");
		return 0;
	}
	int i,j;
	int dim = m1.dimension;

	for(i=0; i < dim; i ++) {
		for(j=0; j < dim; j++) {
			(*ret).data[i][j] = m1.data[i][j] + m2.data[i][j];
 		}
	}
	ret->dimension = dim;
	return 1;
}


/**
 * 
 * @param matrix_t m1
 * @param matrix_t m2
 * @param matrix_t *ret
 *
 */
int matrix_sub(matrix_t m1, matrix_t m2, matrix_t *ret){
	if(m1.dimension != m2.dimension) {
		printf("error: the dimension do not match!\n");
		return 0;
	}
	int i,j;
	int dim = m1.dimension;

	for(i=0; i < dim; i ++) {
		for(j=0; j < dim; j++) {
			(*ret).data[i][j] = m1.data[i][j] - m2.data[i][j];
 		}
	}
	ret->dimension = dim;
	return 1;
}

void matrix_split(matrix_t m, matrix_t *m00, matrix_t *m01, matrix_t *m10, matrix_t * m11) {
	int dim = m.dimension / 2;
	int i,j;
	m00->dimension = m01->dimension = m10->dimension = m11->dimension = dim;
	for(i=0; i < m.dimension; i ++){
		for(j=0; j < m.dimension; j ++){
			if(i < dim && j < dim){
				m00->data[i][j] = m.data[i][j];
			}else if(i < dim && j >= dim) {
				m01->data[i][j - dim] = m.data[i][j];
			}else if(i >= dim && j< dim) {
				m10->data[i - dim][j] = m.data[i][j];
			}else{
				m11->data[i - dim][j - dim] = m.data[i][j];
			}
		}
	}

}

void matrix_multi(matrix_t mt1, matrix_t mt2, matrix_t *ret){
	if(mt1.dimension != mt2.dimension) {
		printf("error:the dimension of the two matrix do not match!\n");
		exit(-1);
	}

	if(mt1.dimension < 2) {
		ret->data[0][0] =  mt1.data[0][0] * mt2.data[0][0];
		ret->dimension = 1;
	}else{
		int dim = mt1.dimension / 2;

		matrix_t m1 ,m2, m3, m4, m5, m6, m7;

		matrix_t a00, a01, a10, a11, b00, b01, b10, b11;

		matrix_t tmp1, tmp2;

		matrix_split(mt1, &a00, &a01, &a10, &a11);
		matrix_split(mt2, &b00, &b01, &b10, &b11);

		matrix_add(a00, a11, &tmp1);
		matrix_add(b00, b11, &tmp2);

		matrix_multi(tmp1, tmp2 , &m1);

		matrix_add(a10, a11, &tmp1);
		matrix_multi(tmp1, b00, &m2);

		matrix_sub(b01, b11, &tmp1);
		matrix_multi(a00, tmp1, &m3);
		matrix_sub(b10, b00, &tmp1); 
		matrix_multi(a11, tmp1, &m4); 
		matrix_add(a00, a01, &tmp1);
		matrix_multi(tmp1, b11, &m5);

		matrix_sub(a10, a11, &tmp1);
		matrix_add(b00, b01, &tmp2);
		matrix_multi(tmp1, tmp2, &m6);


		matrix_sub(a01, a11, &tmp1);
		matrix_add(b10, b11, &tmp2);
		matrix_multi(tmp1, tmp2, &m7);

		matrix_t c1, c2, c3, c4;


		matrix_add(m1, m4, &c1);
		matrix_add(m7, c1, &c1);
		matrix_sub(c1, m5, &c1);


		matrix_add(m3, m5, &c2);

		matrix_add(m2, m4, &c3);

		matrix_add(m1, m3, &c4);
		matrix_add(m6, c4, &c4);
		matrix_sub(c4, m2, &c4);

		int i,j;

		for(i=0;i < dim; i++) {
			for(j=0;j < dim; j++) {
				ret->data[i][j] = c1.data[i][j];
				ret->data[i][j + dim] = c2.data[i][j];
				ret->data[i + dim][j] = c3.data[i][j];
				ret->data[i + dim][j + dim] = c4.data[i][j];
			}
		}
		ret->dimension = mt1.dimension;
	}
}

/**
 * print a matrix . 
 */
void matrix_print(matrix_t m){
	int dim = m.dimension;
	int i, j;
	for(i=0; i < dim; i++) {
		for(j=0; j < dim; j++) {
			printf("%5d", m.data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char **argv) {
	matrix_t m1 = matrix_for_init, m2 = matrix_for_init;
	printf("Please input the first matrix:\n");
	matrix_input(&m1);
	matrix_print(m1);
	printf("Please input the second matrix:\n");
	matrix_input(&m2);
	matrix_print(m2);
	matrix_t ret = matrix_for_init;
	matrix_multi(m1, m2, &ret);
	//matrix_add(m1, m2, &m3);
	matrix_print(ret);
	return 0;
}
