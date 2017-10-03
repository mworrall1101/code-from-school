/* printing.c

   A program demonstrating the use of the printf function. 
   
   To compile, try
     gcc -Wall -std=c99 -o printing printing.c

   B. Bird - 05/06/2016
*/

#include <stdio.h>

int main(){
	int j = 10;
	float f = 6.7;
	//Correct: Print an int with %d
	printf("Here is an int: %d\n", j);
	//Correct: Print a float with %f
	printf("Here is a float: %f\n", f);
	//Incorrect: Print a float with %d
	//printf("Here is an int: %d\n", f);
	return 0;
}
