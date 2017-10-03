import sys

args = sys.argv
num_files = len(args)-2
key_word = args[1]
file_list = []
table_list = []
comma = ","
exclude = ["heading", "values"]
def merge(table1, table2):
	for key1, key2 in zip(table1, table2):
		if key1 is not "values" and key2 is not "values":
			if key1 in table1 and key1 in table2:
				for i in range(table2["values"]):			
					table1[key1].append(table2[key1][i])
			if key1 not in table2:
				for i in range(table2["values"]):
					table1[key1].append("")
	for key2 in table2:
		if key2 not in table1:
			table1[key2] = [""]
			for i in range(table1["values"]-2):
				table1[key2].append("")
			for i in range(table2["values"]):
				table1[key2].append(table2[key2][i])
	
	for key,value in sorted(table1.items()):
		if key not in exclude:		
			s = []
			s.append(key)
			for v in value:
				s.append(v)
			s = comma.join(s)			
			print(s)
		elif key is not "values":
			h = []
			h.append(key_word)
			for v in value:
				h.append(v)
			h = comma.join(h)			
			print(h)

for index in range(2,len(args)):
	file_list.append(args[index])


for file_name in file_list:
	key_index = -1
	f = open(file_name)
	tuple_table = []
	is_heading = 0
	table_dict = {}	
	key_heading = ""
	heading = ""
	num_values = 0
	for line in f:		
		row = line.split(",")
		num_values = len(row)-1
		for i in range(len(row)):
			row[i] = row[i].strip()
#Find the index of the Key column heading (only done once)		
		if is_heading == 0:
			for i in range(len(row)):
				if row[i] == key_word:
					key_index = i
			print(key_index)
			del row[key_index]
			table_dict["heading"] = row
			is_heading = 1
		else:
			table_dict[row[key_index]] = row
			del row[key_index]
		table_dict["values"] = num_values
#Turn the table into a dictionary with each key being the row in the Key column, and the value being the rest of the row associated with the row-key
		
				
		
	f.close()
	

	
	table_list.append(table_dict)
new_dict = {}
table_list.append(new_dict)
	
merge(table_list[0], table_list[1])

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
