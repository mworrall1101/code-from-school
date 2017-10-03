/* global.c


   B. Bird - 05/11/2016
*/

#include <stdio.h>

int X = 100;

void f(){
	X = X - 90;
}

void g(){
	X = X - 4;
}

int main(){
	printf("X = %d\n", X);
	f();
	g();
	printf("X = %d\n", X);
	X++;
	printf("X = %d\n", X);
	return 0;
}
