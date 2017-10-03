import sys
import os

debug = 0
args = sys.argv
if len(args) < 3:
	print("Usage: python3 merge.py <key column name> <file 1> <file 2> <file 3> ...")
	exit()
num_files = len(args)-2
key_word = args[1]
file_list = []
table_list = []
comma = ","
exclude = ["heading", "values"]

#Error codes
KEY_COLUMN_MISSING_ERROR = "Error: key column is missing from one of the tables"
DUPLICATE_KEY_ERROR = "Error: Duplicate row entries in the key column are not allowed"

EMPTY_TABLE_ERROR = "Error: Table must contain at least one non-blank line"
INCONSISTENT_ROWS_ERROR = "Error: All rows must have the same number of entries"



#Takes two tables that are valid and of legal format
# and combines them into the table in the first argument
def merge(table1, table2):
	for key1 in table1:
		if key1 is not "values":
			if key1 in table1 and key1 in table2:
				for i in range(table2["values"]):
					table1[key1].append(table2[key1][i])
			if key1 not in table2:
				for i in range(table2["values"]):
					table1[key1].append("")
	for key2 in table2:
		if key2 not in table1:
			table1[key2] = []
			for i in range(table1["values"]):
				table1[key2].append("")
			for i in range(table2["values"]):
				table1[key2].append(table2[key2][i])
	table1["values"] = table1["values"] + table2["values"]
	
	if debug == 1:	
		print(table1)
		print()
		print(table1["values"])
		print(table2["values"])
		print()


#Prints out a table in csv format	
def print_table(table1):	
	h = []
	h.append(key_word)
	for v in table1["heading"]:
		h.append(v)
	h = comma.join(h)			
	print(h)	
	for key,value in sorted(table1.items()):
		if key not in exclude:		
			s = []
			s.append(key)
			for v in value:
				s.append(v)
			s = comma.join(s)			
			print(s)
		
#Main code segment
#*****************			



for index in range(2,len(args)):
	file_list.append(args[index])

columns = []
headings = ""
for file_name in file_list:
	info = os.stat(file_name)
	if info.st_size == 0:
		print(EMPTY_TABLE_ERROR)
		sys.exit()	
	try:	
		
		
		f = open(file_name)
	except FileNotFoundError:
		print("Error: Unable to open %s"%(file_name))
		sys.exit()
	line = ""	
	while "," not in line:
		line = f.readline().strip()	
	headings = line + headings + ","
if key_word not in headings:
	print(KEY_COLUMN_MISSING_ERROR)
	sys.exit()
columns = headings.split(",")
columns = [word.strip() for word in columns if word.strip() != key_word]
headings = []

for i in range(len(columns)):
	if columns[i] != "":
		headings.append(columns[i])
for i in range(len(headings)):
	if headings.count(headings[i]) > 1:
		print('Error: Column name "%s" occurs too many times'%headings[i])
		sys.exit()
for file_name in file_list:
	key_index = -1
	try:	
		f = open(file_name)
	except FileNotFoundError:
		print("Error: Unable to open %s"%(file_name))
		sys.exit()
	tuple_table = []
	is_heading = 0
	table_dict = {}	
	key_heading = ""
	heading = ""
	num_values = 0
	row_count = 0
	for line in f:
		if ',' not in line:
			continue		
		row = line.split(",")
		prev_num = num_values		
		num_values = len(row)-1
		if is_heading == 1:
			if prev_num != num_values:
				print(INCONSISTENT_ROWS_ERROR)
				sys.exit()
		for i in range(len(row)):
			row[i] = row[i].strip()
#Find the index of the Key column heading (only done once)		
		if is_heading == 0:
			for i in range(len(row)):
				if row[i] == key_word:
					key_index = i
			if key_index == -1:
				print('Error: File %s No column called "%s"'%(file_name, key_word))
				sys.exit()
			del row[key_index]
			table_dict["heading"] = row
			is_heading = 1
		else:
			if row[key_index] in table_dict:
				print("Error: The row key %s occurs multiple times in the table %s"%(row[key_index], file_name))
				sys.exit()
			else:
				table_dict[row[key_index]] = row
				del row[key_index]
		table_dict["values"] = num_values
	f.close()
	table_list.append(table_dict)


for i in range(1, len(table_list)):	
	merge(table_list[0], table_list[i])
print_table(table_list[0])

#for table in table_list:
#	for entry in table["heading"]:
#		print(entry, end=' ')
#	print()
#	for key in table:
#		if key is not "heading":	
#			print(key, end=' ')		
#			for item in table[key]:
#				print(item,end=' ')
#			print()
#	print()
#print()
