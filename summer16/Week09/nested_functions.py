# nested_functions.py
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


outside_function(6,10)
