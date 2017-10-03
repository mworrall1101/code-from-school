#Quiz-2
#
#
#file_search.py
#
# Mark Worrall - July 3, 2016

import sys
import os

current_dir = os.getcwd()

files = [f for f in os.listdir(current_dir)]
print(current_dir)
for e in files:
	if os.path.isfile(e):
		f = open(e)	
		try:
			for line in f: 
				for arg in sys.argv:
					if str(arg) in line:
						print(line, end = ' ')
			f.close()
		except UnicodeDecodeError:
			x = 1
for e in files:
	if os.path.isdir(e):
		l =  [current_dir, e]
		path =  os.path.sep.join(l)
		sub_files = [f for f in os.listdir(path)]
		for e in sub_files:
			if os.path.isfile(e):
				f = open(e)
				for line in f: 
					for arg in sys.argv:
						if str(arg) in line:
							print(line, end = ' ')
				f.close()
				

