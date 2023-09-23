'''Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. 
Write functions to compute following: 
a) The average score of class 
b) Highest score and lowest score of class 
c) Count of students who were absent for the test 
d) Display mark with highest frequency'''

mark=[]
n=int(input("Enter number of students in class :"))
print("Enter -1 if student is absent")
for i in range (n):
	mark.append(int(input("Enter markss of students in class :")))
print("Marks of student in class ",mark)

def average():
	sum=0
	for i in mark:
		if i!=-1:
			sum+=i
	avg=sum/n
	print("Average score of class is ", avg)

def highlow_Score():
	max=mark[0]
	min=mark[0]
	for i in mark:
		if i>max:
			max=i
	for i in mark:
		if i!=-1:
			if i<min:
				min=i
	print("Maximum score of class is ",max)
	print("Minimum score of class is ",min)
	

def absent():
	abst=0
	for i in mark:
		if i==-1:
			abst+=1
	print("Absent number of students in class are :",abst)

def high_frequency():
	freq=[]
	value=[]
	for i in mark:
		if i in value:
			freq[value.index(i)]+=1
		else:
			value.append(i)
			freq.append(1)
	f=max(freq)
	val=value[freq.index(f)]
	print("Marks of highest frequnecy is ",val)
	print("Number of times it occured is ",f)

while True:
	
	print("------MENU------\n1.Average of score\n2.Highest and Lowest of Score\n3.Absent \n4.Highest frequency of score\n5.Exit Program\n-----------------")
	ch=int(input("Enter choice you want :"))

	if ch==1:
		average()

	elif ch==2:
		highlow_Score()

	elif ch==3:
		absent()

	elif ch==4:
		high_frequency()

	else:
		break
print("Exitted Successfully")
	 
			



