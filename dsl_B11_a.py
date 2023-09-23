'''a) Write a Python program to store roll numbers of student in array who attended training program in random order. 
	Write function for searching whether particular student attended training program or not, using Linear search and Sentinel search. '''


def linearSearch(arr,x):
	for i in range (len(arr)):
		if(arr[i]==x):
			return i
	return -1

def sentinelSearch(arr,x):
	l=len(arr)
	arr.append(x)
	i=0
	while(arr[i]!=x):
		i=i+1
	if(i!=l):
		return i
	else:
		return -1
def main():
	print("How many students in class?")
	n=int(input())
	array=[]
	for i in range (n):
		print("Enter roll number in array:")
		array.append(int(input()))
	print("Roll number of students who were present in program :",array)

	while True:
		print("\n1.Linear Search\n2.Sentinel Search\n3.Exit")
		ch=int(input("Enter your choice :"))
		
		if ch==1:
			print("Enter roll no you want to search :")
			key=int(input())
			location=linearSearch(array,key)
			if (location!=-1):
				print("The roll no is present at index",location)
			else:
				print("Roll no is not present")
	
		elif ch==2:
			print("Enter roll no you want to search :")
			key=int(input())
			location=sentinelSearch(array,key)
			if (location!=-1):
				print("The roll no is present at index",location)
			else:
				print("Roll no is not present")
		
		else:
			break
	print("Exitting Program")

main()
			
			
	