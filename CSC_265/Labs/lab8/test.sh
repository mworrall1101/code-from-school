#!/bin/bash

#Bash has a lot to learn and should be looked up as needed 
#man bash contains heaps of info pertaining to bash code
#Or go to tldp.org for introduction to bash
#
#$0 contains the program name
#The other $arguments are variables being passed into the script
echo $0 $1 $2

echo ""

#Functions can be created
#seq is a function which passes a sequence(START, INCREMENT, END)
function something {
	
	for i in $(seq 1 2 9); do
		echo "Iteration # $i."
	done
}
#anything after the function call will be passed into the function as a variable

#something "String"

#`something` is the old syntax for performing a task and then passing output
#now $(something) is used. Whatever is done in the parentheses will be passed into a variable

#Square brackets denote there is an expression contained which will be
#evaluated to true or false. Spaces must be such that 
#["space"something"space"else"space"]
function something2 {

	for i in $(ls $1); do 
		i="$1/$i"
		echo $i
		if [ -d $i ]; then
			something2 $1
		fi
	done

}

something2 "."

#Math in bash must be done in dobule braces (( a + b ))

#other useful things(all have man pages):
#bc - arbitrary precision calculator
#
