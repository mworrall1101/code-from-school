/* capitalize.c
 
   Read characters from standard input, capitalize them,
   then print the resulting characters to standard output.

   B. Bird - 05/13/2016
*/

#include <stdio.h>
#include <ctype.h>


int main(){

	//The global variables stdin, stdout and stderr
	//are streams of type FILE* which refer to standard
	//input, standard output and standard error, 
	//respectively.
	FILE* input_file = stdin;
	int c = fgetc(input_file);
	while(c != EOF){
		char uppercase_c = toupper(c);
		fprintf(stdout,"%c",uppercase_c);
		c = fgetc(input_file);
	}
	//The stderr stream is useful for status messages or errors,
	//since it is generally directed to the operator of the program
	//(e.g. the console or a log file). By contrast, standard output
	//may be directed to the console, but may also be redirected
	//or piped, so error messages printed to stdout may not reach
	//the user.
	fprintf(stderr,"Done reading\n");
	return 0;
}
