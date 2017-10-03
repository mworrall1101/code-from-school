# scope.py
#
#
#
# B. Bird - 06/28/2016

#This variable is at the global scope
X = 10


def F():
	#Create a new variable X in the local scope of F
	X = 6
	print("In F: X = %d"%X)

def G():
	#The directive below binds X to the global version
	global X
	X = 6
	print("In G: X = %d"%X)

print("At global scope: X = %d"%X)
F()
print("At global scope: X = %d"%X)
G()
print("At global scope: X = %d"%X)
