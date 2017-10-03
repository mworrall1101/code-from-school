/* pointers3.c


   B. Bird - 05/18/2016
*/

#include <stdio.h>

void F(int x, int y){
	x = y;
}

void G(int* p, int* q){
	p = q;
}

void H(int* p, int* q){
	*p = *q;
}

int main(){
	
	int i = 6;
	int j = 10;
	printf("i = %d, j = %d\n",i,j);
	F(i,j);
	printf("i = %d, j = %d\n",i,j);
	G(&i,&j);
	printf("i = %d, j = %d\n",i,j);
	H(&i,&j);
	printf("i = %d, j = %d\n",i,j);
		
	return 0;
}
