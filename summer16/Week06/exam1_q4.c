/* exam1_q4.c

   Code for question 4 (Pointers) of SENG 265 Summer 2016 Exam 1.

   B. Bird - 05/25/2016
*/

#include <stdio.h>

void G(int** C){
	*C = (*C) + 1;
}

void F(int* A, int* B){
	printf("*A = %d, *B = %d\n", *A, *B);
	*A = 10;
	G(&A);
	printf("*A = %d, *B = %d\n", *A, *B);
}

int main(){
	int X[4] = {106, 205, 265, 226};
	int* Y = &X[0];
	int* Z = &X[1];
	printf("Elements of X: %d %d %d %d\n", X[0], X[1], X[2], X[3]);
	printf("*Y = %d, *Z = %d\n", *Y, *Z);
	F(Y, Z);
	printf("*Y = %d, *Z = %d\n", *Y, *Z);
	printf("Elements of X: %d %d %d %d\n", X[0], X[1], X[2], X[3]);
	return 0;
}
