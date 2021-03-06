'''
	print_lines.py
	This is the working solution for Quiz 2
	Mark Worrall - July 7, 2016

'''

import os
import sys

WIDTH1 = 30
WIDTH2 = 70

def get_lines(directory='.', keywords = []):
	files = os.listdir(directory)
	filelist = []
	for my_file in files:
		my_file = os.path.join(directory, my_file)
		if(os.path.isdir(my_file)):
			get_lines(my_file, keywords)
		
		if(os.path.isfile(my_file)):
			f = open(my_file)
		
			try:
				for line in f:
					for word in keywords:
						if word in line:
							if len(line.strip()) > WIDTH2 or len(my_file) > WIDTH1:
								print('...'+my_file.ljust(WIDTH1)[-(WIDTH1-3):]+':', (line.strip()+'...').rjust(WIDTH2)[0:(WIDTH2-3)]+'...')
							else:
								print(my_file.ljust(WIDTH1)+':', line.strip().rjust(WIDTH2))
			except UnicodeDecodeError:
				print(end='')
			f.close()

keywords = []


for i in range(1,len(sys.argv)):
	keywords.append(sys.argv[i])
print('\n Found lines containing:', end=' ')

for i in range(0,len(keywords)-1):
	print(keywords[i],end=', ')
print(keywords[len(keywords)-1])
print('\n')

print("File Path".center(WIDTH1), "Found Text".center(WIDTH2))
head1 = '-'
head2 = '-'
for i in range(WIDTH1-5):
	head1 = head1+'-'
for i in range(WIDTH2-5):
	head2 = head2+'-'
print(head1.center(WIDTH1), head2.center(WIDTH2))
print('\n')

get_lines(".", keywords)
print(end='\n\n\n')

