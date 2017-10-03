# table_to_dict.py
#
#
#
# B. Bird - 06/28/2016

import sys

#Create a new exception type (subclassed from 'Exception')
#to represent duplicate key errors
class DuplicateKeyError(Exception):
	#The __init__ method is the constructor
	#All instance methods take a parameter 'self'
	#as their first argument.
	#When the instance method is called, the 'self'
	#parameter is not provided by the caller.
	#To create an instance of DuplicateKeyError
	#with the invalid_key 100, the constructor would be
	#invoked with 'DuplicateKeyError(100)'
	def __init__(self, invalid_key):
		#Create an instance variable called 'bad_key'
		self.bad_key = invalid_key

# table_to_dict( T, key_column_index )
#
# Given a table T (which will be a list of lists), where
# each element of T is one row of the table, return a 
# dictionary whose keys are the entries in column
# key_column_index of the table and whose values are
# the row associated with each key (with the key itself
# removed from the row).
#
# If a key appears more than once, this function will
# raise a DuplicateKeyError.
#
# For example, if the input table is
#    [ ('V00123456', 10, 1),
#      ('V00123654', 11, 6),
#      ('V00000123', 15, 6) ]
# and key_column_index is 0, then the resulting
# dictionary will be
#    { 'V00123456': [10, 1],
#      'V00123654': [11 ,6],
#      'V00000123': [15, 6]}
# If key_column_index is 1, then the resulting
# dictionary will be
#    { 10: ['V00123456',1],
#      11: ['V00123654',6],
#      15: ['V00000123',6]}
# If key_column_index is 2, then a DuplicateKeyError
# will be raised, since the key 6 appears twice.
def table_to_dict(T, key_column_index):
	output_dict = {}
	for row in T:
		key = row[key_column_index]
		rest_of_row = row[0:key_column_index] + row[key_column_index+1:]
		if key in output_dict:
			raise DuplicateKeyError(key)
		output_dict[key] = rest_of_row
	return output_dict





L =   [ ('V00123456', 10, 1),
        ('V00123654', 11, 6),
        ('V00000123', 15, 6) ]

print("Calling table_to_dict(L,0)")
print(table_to_dict(L,0))
print("Calling table_to_dict(L,1)")
print(table_to_dict(L,1))
print("Calling table_to_dict(L,2)")
try:
	print(table_to_dict(L,2))
except DuplicateKeyError as e:
	#Print the error message to stderr.
	#A file handle for stderr is available as sys.stderr
	print('Duplicate key '+ str(e.bad_key), file=sys.stderr)
