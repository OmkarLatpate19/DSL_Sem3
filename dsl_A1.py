groupA=[]
groupB=[]
groupC=[]
cricbad=[]
eitheror=[]
neithernor=[]
cricfoot=[]

def cricket():
	c=int(input("Enter number of students playing cricket :"))
	for i in range(c):
		#rollno=int(input("Enter roll numbers of students playing cricket :"))
		groupA.append(int(input("Enter roll numbers of students playing cricket :")))
	print("Students playing cricket are :", groupA)

def badminton():
	b=int(input("Enter number of students playing badminton :"))
	for i in range(b):
		rollno=int(input("Enter roll numbers of students playing badminton :"))
		groupB.append(rollno)
	print("Students playing badminton are :", groupB)

def football():
	f=int(input("Enter number of students playing football :"))
	for i in range(f):
		rollno=int(input("Enter roll numbers of students playing football :"))
		groupC.append(rollno)
	print("Students playing football are :", groupC)

def cric_bad():
	cricbad=groupA + groupB
	for i in groupA:
		if i in groupB:
			cricbad.remove(i)
	print("Students playing cricket and badminton are : ",cricbad)

def either_or():
	for i in groupA:
		if i not in groupB:
			eitheror.append(i)
	for i in groupB:
		if i not in groupA:
			eitheror.append(i)
	print("Students playing either cricket or badminton but not both :", eitheror)

def neither_nor():
	for i in groupC:
		if i not in groupA + groupB:
			neithernor.append(i)
	print("Students playing neither cricket nor badminton : ",neithernor)
	print("Number of students playing neither cricket nor badminton : ",len(neithernor))

def cric_foot():
	cricfoot= groupA + groupC
	for i in groupA:
		if i in groupC:
			cricfoot.remove(i)
	for i in groupB:
		if i in cricfoot:
			cricfoot.remove(i)
	print("Students playing cricket and football but not badminton :",cricfoot)



cricket()
badminton()
football()
cric_bad()
either_or()
neither_nor()
cric_foot()
	
		

