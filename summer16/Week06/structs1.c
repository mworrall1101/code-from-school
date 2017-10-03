/* structs1.c
  
   B. Bird - 06/07/2016
*/

#include <stdio.h>
#include <string.h>

/* Create a type called "struct StudentStruct"
   which refers to a struct containing a float
   and a char array of length 100.
*/
struct StudentStruct {
	float grade;
	char name[100];
};

/* Create a type called "Student" which is an alias
   of the type "struct StudentStruct"
*/
typedef struct StudentStruct Student;

/* A function to return a student's grade.
   Note that since s is not a pointer, the value
   passed in from the caller is a copy of the caller's
   data
*/
float get_grade( Student s ){
	return s.grade;
}

/* Multiply a student's grade by 2.
   In this case, s is a pointer, so the caller's
   original data can be modified by the function.
*/
void double_grade( Student* s ){
	//The notation "(*s).grade" is equivalent
	//to the notation "s->grade".
	s->grade = 2*(   (*s).grade   );
}

int main(){
	//Create an instancee of struct StudentStruct
	//called "bill". Note that the declaration
	//"Student bill;" would be equivalent.
	struct StudentStruct bill;

	//Set the grade to 10 (remember that the . operator
	//can only be used on an actual struct, not a pointer
	//to a struct).
	bill.grade = 10;
	//Copy the string "Bill" into the name attribute.
	strcpy(bill.name, "Bill");

	printf("Name: %s, Grade: %f\n", bill.name, get_grade(bill) );

	double_grade( &bill );
	
	printf("Name: %s, Grade: %f\n", bill.name, get_grade(bill) );
	return 0;
}

