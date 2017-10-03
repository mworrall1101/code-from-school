/* strings_equal.c


   B. Bird - 05/10/2016
*/

#include <stdio.h>
#include <string.h>

/* strings_equal(s1, s2)
   Test whether the two provided C strings are equal.
   If they are equal, return 1. Otherwise, return 0.
   
   Pre-conditions:
     s1 and s2 are valid, null terminated C strings.
   Return value: 
     1 if strings s1 and s2 are equal.
     0 otherwise
*/
int strings_equal(char s1[], char s2[]){
	/* 
	int i = 0;
	while(s1[i] != '\0' && s2[i] != '\0'){
		if (s1[i] != s2[i])
			return 0;
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return 1;
	return 0;
	*/
	int length1 = strlen(s1);
	int length2 = strlen(s2);
	if (length1 != length2)
		return 0;
	int i;
	for(i = 0; i < length1; i++){
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}

int main(){
	// Add some test cases for strings_equal here...
	return 0;
}
