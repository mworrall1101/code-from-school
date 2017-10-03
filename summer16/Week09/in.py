# in.py
#
#
#
# B. Bird - 06/28/2016



#Create a list L
L = [1,10,6,42,100]

#The 'in' operator on a list or tuple uses linear search
if 10 in L:
	print("L contains the value 10")
else:
	print("L does not contain the value 10")

#Create a dictionary D

D = {1:'Hello', 2:'World'}

#The 'in' operator on a dictionary searches for a specific
#key. It is typically very fast (expected O(1) under certain
#conditions).
if 10 in D:
	print("D contains the key 10")
else:
	print("D does not contain the key 10")


#Create a set S
#Sets do not have key/value pairs, and are similar
#to lists, except that they are optimized for searching
#and have no fixed ordering. (You can still iterate
#over sets with a for loop, but the order in which
#elements are visited is arbitrary).
S = set()
S.add(6)
S.add(10)
S.add(15)

if 10 in S:
	print("S contains the element 10")
else:
	print("S does not contain the element 10")

