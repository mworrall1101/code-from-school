# table_to_csv.py
# Converts a table in HTML format and converts it to CSV
# Mark Worrall - 07/19/16

import sys
import re
string = ""
i = 0
for line in sys.stdin:
	
	if'<table' in line:
		print('Table %d'%i)
		i+=1
		
	string = string+line.strip()
print(string)
table_p = r'<table.*?>((?:<tr.*?>(?:<t(?:h|d).*?>.*?</t(?:h|d).*?>)+</tr.*?>)*)</table.*?>'
t = re.compile(table_p, re.IGNORECASE|re.DOTALL)
tables = t.findall(string)
#print(tables)
row_p =r'<tr.*?>((?:<t(?:h|d).*?>.*?</t(?:h|d).*?>)+)</tr.*?>'
row_matcher = re.compile(row_p)
count = 0
for table in tables:
	count+=1;
	print('Table %d'%count)	
	rows = row_matcher.findall(table)
	data_p = r'<t(?:h|d).*?>(.*?)</t(?:h|d).*?>'	
	data_matcher = re.compile(data_p)
	for row in rows:
		data = data_matcher.findall(row)
		print(data)
	








