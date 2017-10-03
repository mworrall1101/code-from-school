/* pointers5.c


   B. Bird - 05/27/2016
*/

#include <stdio.h>

int main(){
	
	int A[5] = {0,20,6,10,50};
	int* p = &A[0];
	int* q = &A[2];

	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	
	*p = (*p) + 1;	
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	
	q = q + 1;
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	
	p = q - 1;	
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	
	*(p-1) = 19;
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	
	q = &A[1];
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	
	p = &A[0];
	*p = 0;
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	
	*A = 100;
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);

	*(A + 1) = 1900;
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);

	q[0] = 17;
	*(q + 0) = 17;
	*(0 + q) = 17;
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);

	0[q] = 17124;
	printf("A = {%d, %d, %d, %d, %d}\n",A[0],A[1],A[2],A[3],A[4]);
	printf("*p = %d, *q = %d\n", *p, *q);
	return 0;
}


