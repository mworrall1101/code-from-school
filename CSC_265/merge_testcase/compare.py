import os
import sys

args = sys.argv

my_file = args[1]
model_file = args[2]

def parse_file(file_name):	
	f = open(file_name)
	table = []
	for line in f:
		row  = line.split(',')
		if row[0].strip() == '':
			continue
		table.append(row)
	f.close()
	return table


my_table = parse_file(my_file)

model_table = parse_file(model_file)

for i in range(len(my_table)):
		
	if my_table[i] != model_table[i]:
		mystr = ','.join(my_table[i])
		modelstr = ','.join(model_table[i])
		print("Rows are different \n my row: %s \n model row: %s" %(mystr, modelstr))
