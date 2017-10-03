# arguments.py
#
#
#
# B. Bird - 06/28/2016

import sys

#The command line arguments to the program are stored in sys.argv,
#which is a list.

print("Number of arguments: %d"%len(sys.argv))

arg_num = 0
for arg in sys.argv:
	print("Argument %d: '%s'"%(arg_num, arg))
	arg_num = arg_num + 1
