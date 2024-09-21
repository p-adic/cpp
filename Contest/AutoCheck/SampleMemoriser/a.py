contest_num = 511
start_hour = 21
start_minute = 20
wait = True
#wait = False

import datetime
two_byte_message = open("two_byte_message.txt",'r')
message_list = [line.rstrip('\n')for line in two_byte_message.readlines()]
two_byte_message.close()
init = True
while wait:
	now = datetime.datetime.now()
	if start_hour <= now.hour and start_minute <= now.minute and 5 <= now.second:break
	elif init:
		init = False
		print(message_list[0],str(now.hour),message_list[1],str(now.minute),message_list[2],str(now.second),message_list[3])
		print("https://yukicoder.me/contests/" + str(contest_num),message_list[4])

import requests
from bs4 import BeautifulSoup
print("https://yukicoder.me/contests/" + str(contest_num),message_list[5])
contest_table_page_url = "https://yukicoder.me/contests/" + str(contest_num) + "/table"
contest_table_page = BeautifulSoup(requests.get(contest_table_page_url).text,'html.parser')
problem_order_list = []
for a_tag in contest_table_page.find_all("a"):
	temp = str(a_tag)
	if temp[:22] != "<a href=\"/problems/no/":continue
	temp = temp.split('\"')[1]
	problem_order = contest_table_page.find("a",{"href":temp}).text.split()[0]
	problem_order_list += [problem_order]
	problem_page_url = "https://yukicoder.me" + temp
	problem_page = BeautifulSoup(requests.get(problem_page_url).text,'html.parser')
	count = 100
	count_list = []
	for sample in problem_page.find_all("div",{"class":"sample"}):
		count += 1
		temp = str(sample).split("<pre>")
		input_file = open("Sample/" + problem_order + "/input/sample" + str(count)[1:] + ".txt",'w')
		output_file = open("Sample/" + problem_order + "/output/sample" + str(count)[1:] + ".txt",'w')
		if len(temp) < 3:
			print(problem_order,message_list[6],str(count%100),message_list[7])
		else:
			if len(temp) != 3:print(problem_order,message_list[6],str(count%100),message_list[8])
			for i,file in zip([1,2],[input_file,output_file]):
				temp[i] = temp[i].split("</pre>")[0]
				if temp[i][-1] != '\n':temp[i] += '\n'
				file.write(temp[i])
				file.close()
		count_list += [str(count)[1:]+'\n']
	count_file = open("Sample/" + problem_order + "/count.txt",'w')
	count_file.write(str(len(count_list))+'\n')
	for valid_count in count_list:count_file.write(valid_count)
	count_file.close()
	print(problem_order,message_list[9],len(count_list),message_list[10])
problem_order_file = open("Sample/problem_order.txt",'w')
problem_order_file.write(str(len(problem_order_list))+'\n')
for valid_problem_order in problem_order_list:problem_order_file.write(valid_problem_order)
problem_order_file.close()
print(message_list[11])
while True:
	print(message_list[12])
	finish = input()
	if finish == "y":break