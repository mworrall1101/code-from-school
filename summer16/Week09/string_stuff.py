# string_stuff.py
#
#
#
# B. Bird - 06/28/2016

S = '     Pear,    Raspberry,     Peach '

#The .split() method of a string splits the string
#by the provided separator and returns a list
#of the resulting tokens.

for token in S.split(','):
	print("Token: '%s'"%token)

#The .strip() method of a string removes all leading
#and trailing whitespace from a string.

for token in S.split(','):
	print("Token: '%s'"%token.strip())
