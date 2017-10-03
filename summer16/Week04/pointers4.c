/* pointers4.c

   An ugly code tracing exercise.

   B. Bird - 05/24/2016
*/

#include <stdio.h>

void G( char* x, char* y, char** z){
	*z = y;
}
void F( char* a, char* b, char* c){
	*a = 'A';
	*b = 'B';
	G(a, b, &c);
	*a = *c;
	printf("In F: %c %c %c\n", *a, *b, *c); 
}
void H( char a, char b, char *c){
	a = *c;
	b = *c;
	*c = a;
}
int main(){
	char c1 = 'X';
	char c2 = 'Y';
	char c3 = 'Z';
	char* q = &c3;
	printf("In main: %c %c %c %c\n", c1, c2, c3, *q);
	F(&c1, &c2, q);
	printf("In main: %c %c %c %c\n", c1, c2, c3, *q);
	G(&c1, &c2, &q);
	printf("In main: %c %c %c %c\n", c1, c2, c3, *q);
	return 0;
}


