# functions.py
#
#
#
# B. Bird - 06/24/2016


def absolute_value(x):
	if x < 0:
		return -x
	else:
		return x


values = (10, -6, 1, 0, -1)
for i in values:
	print("The absolute value of %d is %d"%(i, absolute_value(i)))


def fibonacci(n):
	#Question: What should happen if n is negative?
	if n == 0 or n == 1:
		return 1
	return fibonacci(n-1) + fibonacci(n-2)

print("The 6th Fibonacci number is %d"%fibonacci(6))
