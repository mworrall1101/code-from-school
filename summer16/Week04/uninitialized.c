/* uninitialized.c


   B. Bird - 05/06/2016
*/

#include <stdio.h>

void F(int x){
	int i = 10;
	printf("In F: x = %d, i = %d\n",x,i);
}

void G(int y){
	//Create a variable j and leave it uninitialized, so that
	//it contains whatever data was already present in memory
	//at that location (likely the same space used for the
	//variable i in function F).
	int j;
	printf("In G: y = %d, j = %d\n",y,j);
}

int main(){
	F(5);
	G(17);
	return 0;
}
