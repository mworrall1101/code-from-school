# reading_files.py
#
#
#
# B. Bird - 06/28/2016

filename = 'macbeth.txt'
#The open() function opens a file
#It can be used similar to fopen in C,
#for example open(filename, 'r') or open(filename,'w').
#If the second argument (the mode) is not provided,
#it is assumed to be 'r'.
#The return value of open() is a file object.
#If open() cannot open the file, an IOError is raised.

print("First example:")
f = open(filename)

#f can be iterated over like a sequence. The 'elements'
#of the sequence are the lines of the file.
for line in f:
	#Note that the trailing newline is left in the
	#string.
	print("Line: '%s'"%line)
f.close()


print("Second example:")

#The "with" statement automatically closes the file
#in the event of an error (so no call to f.close() is needed)

with open(filename) as f:
	for line in f:
		#The .strip() method of a string removes
		#leading and trailing whitespace.
		print("Line: '%s'"%( line.strip() ) )


