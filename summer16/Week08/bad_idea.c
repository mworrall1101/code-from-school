/* bad_idea.c

   Exhaust the available memory with an infinite loop
   which calls malloc. This will eventually be terminated
   by the operating system after the process reaches the upper
   limit on its available memory, but until then, may cause
   instability that affects other processes.


   B. Bird - 06/21/2016
*/
#include <stdlib.h>
#include <stdio.h>


int main(){
	
	while(1){
		void* v = malloc(1000);
	}

	return 0;
}
