/* pointers1.c


   B. Bird - 05/18/2016
*/

#include <stdio.h>

int main(){
	
	int x;
	int y;

	x = 6;
	y = 10;

	int* p;
	p = &x;
	printf("x = %d\n",x);
	*p = 17;
	printf("x = %d\n",x);



		
	return 0;
}
