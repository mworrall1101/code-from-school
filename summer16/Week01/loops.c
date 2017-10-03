/* loops.c


   B. Bird - 05/06/2016
*/

#include <stdio.h>

int square(int x){
	int result = x*x;
	return result;
}


int main(){
	int i;
	for(i = 0; i < 10; i++){
		printf("%d squared is %d\n",i,square(i));
	}
	return 0;
}
