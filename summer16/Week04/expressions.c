/* expressions.c

   Practice with expression evaluation.

   B. Bird - 05/25/2016
*/

#include <stdio.h>

void print_value( int value ){
	printf("Value: %d\n", value);
}

int main(){

	int i;
	print_value( i );
	int j = 10;
	print_value( j + 10 );

	//Assignment statements are expressions, and the
	//result of an assignment expression is the final
	//value of the right hand side.
	print_value( i = 6 );
	print_value( i = j + 10);
	print_value( i = i + j + 10);

	//The += operator is equivalent to a regular assignment,
	//so i += j is equivalent to i = i + j.
	i = 6;
	print_value( i += j );

	//The expression ++i is equivalent to i = i + 1,
	//so it adds one to i, stores the result in i, then
	//returns the new value of i.
	i = 6;
	print_value( ++i );

	//The expression i++ is not directly equivalent to a simple
	//assignment expression. The notation i++ adds one
	//to i, stores the result in i, then returns the
	//old value of i.
	//
	//Exercise: Construct a single statement which has
	//the same effect and return value as i++ without
	//using the ++ operator.
	i = 6;
	print_value( i++ );

	i = 6;
	int k = 100;
	print_value( j = i++ + ++k );

	return 0;
}


