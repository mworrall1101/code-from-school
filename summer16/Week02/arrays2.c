/* arrays2.c


   B. Bird - 05/10/2016
*/

#include <stdio.h>

/* class_average(grades)
   Return the average of the elements of the array grades.
   Note that the average has type float.

   Pre-conditions:
     The array grades contains a sequence of 0 or more
     non-negative integers, followed by a -1 to denote
     the end of the sequence.
   Return value:
     The average of the elements of grades.
*/
float class_average(int grades[]){
	int i = 0;
	float sum = 0;
	while(grades[i] != -1){
		sum += grades[i];
		i++;
	}
	return sum/i;
}

int main(){
	int x = 1250;
	int grades1[] = {90, 75, 80, 95,-1};
	int y = 6000;
	float average1 = class_average(grades1);
	printf("Average: %f\n",average1);

	int grades2[] = {100, 90, 60, 70, 80,-1};
	float average2 = class_average(grades2);
	printf("Average: %f\n",average2);
	return 0;
}
