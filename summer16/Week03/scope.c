/* scope.c


   B. Bird - 05/18/2016
*/

#include <stdio.h>


int i = 100;

void G(){
	printf("In G: i = %d\n", i);
}


void F(int i){
	printf("In F (before assignment): i = %d\n", i);
	i = 10;
	printf("In F (after assignment): i = %d\n", i);
}


int main(){
	int i = 6;
	printf("In main (beginning): i = %d\n",i);
	F(i);
	printf("In main (after calling F): i = %d\n",i);
	if (i < 10){
		int i = 17;
		printf("In if-statement: i = %d\n",i);
		F(i);
		printf("In if-statement (after calling F): i = %d\n",i);
	}
	printf("In main (before calling G): i = %d\n", i);
	G();
	printf("In main (end): i = %d\n",i);	
	return 0;
}
