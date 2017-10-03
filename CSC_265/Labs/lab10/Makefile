
#Makefile format:
#
#target: dep
#	command

# for command "echo 'a string'"
#to supress the ech command being written to the output,
# the syntax "@echo 'a string'" will only print out the output of echo
# eg. "A string"

CFLAGS = -Wall -std=c99 -pg
CC = gcc
OFILES  = main.o my_util.o
HFILES = my_util.h my_sort.h



# Special Variables: 
#	$@ contains the target
#	$< contains first item listed after the target label
#	$^ contains all of the dependencies listed after the target

#The % is used as a wildcard
#This target will create a .o file for each .c file
%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) $< -c -o $@

#When 'make all' is called to make the all target, the program flows down
#from here, so that the %.o target will only be called when it is recquired 
#as a dependency
all: sort1 sort2

#The command for this target will always produce an exe with the same 
#name as the target label which is contained in $@
sort1: $(OFILES) my_sort1.o
	$(CC) $(CFLAGS) $^ -o $@

sort2:$(OFILES) my_sort2.o
	$(CC) $(CFLAGS) $^ -o $@

#If a file called clean exists, make will ignore the clean target.
#To force the clean target to run, an arbitrary target with clean as
# a dependancy will override the skipping of clean.
#Eg: skipfix: clean

clean:
	rm -f sort1 sort2
