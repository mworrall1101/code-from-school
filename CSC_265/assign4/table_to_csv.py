# table_to_csv.py
# Converts a table in HTML format and converts it to CSV
# All spaces and tabs are collapsed to a single space. EG: Tom     Arnold -> Tom Arnold
# If any row in a table is less than the max row length for the given table, the row is 
# 	padded with empty cells at the end.
# Output is in the form:
#
#	TABLE 1:
#	<table rows>
#
#	TABLE 2: 
#	<table rows>
#
#  	     .
#	     .
#	     .
#
# Mark Worrall - 07/19/16

import sys
import re
string = ""

for line in sys.stdin:
	string = string+line.strip()
table_p = r'<table.*?>(.*?(?:<tr.*?>.*?(?:<t(?:h|d).*?>.*?</t(?:h|d).*?>)+.*?</tr.*?>)*.*?)</table\s*?>'
t = re.compile(table_p, re.IGNORECASE|re.DOTALL)
tables = t.findall(string)
row_p =r'<tr.*?>(.*?(?:<t(?:h|d).*?>.*?</t(?:h|d).*?>)+.*?)</tr.*?>'
row_matcher = re.compile(row_p, re.IGNORECASE|re.DOTALL)
count = 0

for table in tables:
	row_len = 0
	count+=1;
	row_list = []
	print('TABLE %d:'%count)	
	rows = row_matcher.findall(table)
	data_p = r'<t(?:h|d).*?>(.*?)</t(?:h|d).*?>'	
	data_matcher = re.compile(data_p, re.IGNORECASE|re.DOTALL)
	for row in rows:
		data = data_matcher.findall(row)
		data = [i.strip() for i in data]
		if len(data) > row_len:
			row_len = len(data)		
		for i in range(len(data)):
			data_list = [x.strip() for x in re.findall(r'[^\s\t\n]+[\s\t\n]+?', data[i])]
			data[i] = ' '.join(data_list)
		row_string = ','.join(data)
		row_list.append(row_string)
	for row in row_list:
		while row.count(",") < (row_len-1):
			row = row + ","
		print(row)
	
	print('\n')
	








