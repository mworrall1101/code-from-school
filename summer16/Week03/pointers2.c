/* pointers2.c


   B. Bird - 05/20/2016
*/

#include <stdio.h>

int main(){
	
	int x = 6;
	int y = 10;
	printf("x = %d, y = %d\n",x,y);

	//Declare a pointer p and initialize it to point to x
	int* p;
	p = &x;

	//Declare a pointer q and initialize it to point to x
	int* q;
	//Two ways to set q to be a pointer to x:
	//q = &x;
	q = p;

	//Set x to 17 using q
	*q = 17; 
	printf("x = %d, y = %d\n",x,y);

	//Set x to 100 using p
	*p = 100;
	printf("x = %d, y = %d\n",x,y);

	//Set p to point at y
	p = &y;
	printf("x = %d, y = %d\n",x,y);

	//Set y to 0 using p
	*p = 0;
	printf("x = %d, y = %d\n",x,y);
	
	//Reinitialize x and y to 6 and 10
	x = 6;
	y = 10;

	//Create a pointer R which points at p
	int** R;
	R = &p;
	printf("x = %d, y = %d\n",x,y);

	//Using R, set y to 17
	**R = 17;	
	printf("x = %d, y = %d\n",x,y);

	//Using R, set q to point at y
	q = *R;
	printf("x = %d, y = %d\n",x,y);
		
	//Using q, set y to -1
	*q = -1;
	printf("x = %d, y = %d\n",x,y);
	return 0;
}




