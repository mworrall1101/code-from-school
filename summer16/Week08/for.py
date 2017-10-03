# for.py
#
#
#
# B. Bird - 06/24/2016


#For loops iterate over sequences,
#which include lists, strings and tuples.

L = [10, 20, 30, 40, 50]

for x in L:
	print("x = %d"%x)

L = [10, 20, 'A','B','C']

#The isinstance function returns True
#if the provided value has the provided type.
for x in L:
	if isinstance(x,int):
		print("x = %d"%x)
	elif isinstance(x,str):
		print("x = %s"%x)

#The range() function returns a sequence
#of integers in a range.

#When called with one argument, such as range(n),
#range generates the sequence 0, 1, 2, ..., n-1.

#Generate the range 0, 1, 2, ..., 9
for i in range(10):
	print('i = %d'%i)

#When called with two arguments, such as range(m, n),
#range generates the sequence m, m+1, m+2, ..., n-1

#Generate the range 10, 11, 12, 13
for j in range(10,14):
	print("j = %d"%j)

