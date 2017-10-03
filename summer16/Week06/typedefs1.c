/* typedefs1.c
  
   B. Bird - 06/07/2016
*/

#include <stdio.h>

#define NUM_GRADES 4

typedef int Grade;
typedef Grade GradeArray[NUM_GRADES];

double compute_average(GradeArray A){
	double sum = 0;
	int i;
	for (i = 0; i < NUM_GRADES; i++)
		sum += A[i];
	return sum/NUM_GRADES;
}

int main(){
	
	Grade g = 10;
	int x = g;

	GradeArray grades = {10,20,30,40};

	printf("Average: %f\n", compute_average(grades));


	return 0;
}

