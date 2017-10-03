/* split_process.c


   B. Bird - 06/22/2016
*/

#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Starting...\n");
	sleep(5); //Wait for 5 seconds
	fork();
	printf("After fork\n");
	sleep(10);
	return 0;
}
