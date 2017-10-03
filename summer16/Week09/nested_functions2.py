# nested_functions2.py
#
#
#
# B. Bird - 06/28/2016

def outside_function(x,y):
	
	z = x + y
	def inside_function(a,b):
		print("Inside: %d %d %d %d %d"%(x,y,z,a,b))
		return z + a + b
	print("Outside: %d %d %d"%(x,y,z))
	value = inside_function(3,4)
	print("Return value: %d"%value)
	print("Outside: %d %d %d"%(x,y,z))
	return inside_function
	
F1 = outside_function(6,10)
F2 = outside_function(-1,-2)

print("Calling the two returned functions with arguments (0,0)")
F1(0,0)
F2(0,0)
