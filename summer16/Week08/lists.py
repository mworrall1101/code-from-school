# lists.py
#
#
#
# B. Bird - 06/22/2016


#Create a list containing 1,2,3,4,5
L = [10,11,12,13,14]

#The len function returns the length of a sequence.
print('Length of L: %d'%len(L))

#Lists support array-like notation to access indices.
i = 0
while i < len(L):
	print('L[%d] = %d'%(i,L[i]))
	i += 1

#Lists also support negative indices. The index -1
#is the last element, the index -2 is the second-last,
#and so on.
print("L[-1] = %d"%L[-1])

#Passing a list directly to print() produces a string
#representation.
print(L)

#A sublist (or 'slice') containing a contiguous set
#of elements can be created with the notation L[start:end],
#where start and end are indices. The result of L[start:end]
#is a new list containing indices start, start+1, ..., end-2, end-1
#of the list L.
print(L[0:2])
print(L[0:-1])

#The del statement can be used to delete elements of a list.
print("Before del[1]:")
print(L)
del L[1]
print("After del[1]:")
print(L)

#Elements can be added to a list with the .append method
L.append(100)
#There is no requirement that the elements of a list have the
#same type.
L.append('A')
print("After two appends:")
print(L)

#The 'in' operator can be used to search lists (or any other sequence)
if 10 in L:
	print("L contains the element 10")
else:
	print("L does not contain the element 10")
if 6 in L:
	print("L contains the element 6")
else:
	print("L does not contain the element 6")

#Lists are instances of the list class,
#which can also be instantiated with its constructor.
#e.g. L = list()

#A tuple is similar to a list, but is immutable (i.e. cannot be modified)
T = (100,200,300,400,500)
i = 0
while i < len(T):
	print("T[%d] = %d"%(i,T[i]))

#Operations like T.append(6) or T[0] = 10 are not allowed on tuples.
#Read-only operations (like T[0:3] or "6 in T") are allowed.
