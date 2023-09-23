'''b) Write a Python program to store roll numbers of student array who attended training program in sorted order.
	Write function for searching whether particular student attended training program or not, using Binary search and Fibonacci search.'''

def binarySearch(arr,key):
	low=0
	high=len(arr)-1
	m=0
	while (low<=high):
		m= (low+high)//2
		if (key<arr[m]):
			high=m-1
		elif (key>arr[m]):
			low=m+1
		else:
			return m
	return -1

def fibSearch(arr,key,n):
	b=0
	a=1
	f=b+a
	while(f<n):
		b=a
		a=f
		f=b+a
	offset=-1
	while(f>1):
		i=min(offset+b,n-1)
		if(arr[i]<key):
			f=a
			a=b
			b=f-a
			offset=i
		elif (arr[i]>key):
			f=b
			a=a-b
			b=f-a
		else:
			return i
	if(a and arr[offset+1]==key):
		return offset+1
	return -1

def main():
	print("How many students in class?")
	p=int(input())
	array=[]
	print("Enter roll numbers in array:")
	for i in range (p):
		array.append(int(input()))
	print("Roll number of students who were present in program :",array)

	while True:
		print("\n1.Binary Search\n2.Fibonacci Search\n3.Exit")
		ch=int(input("Enter your choice :"))

		if ch==1:
			print("Enter roll no you want to search :")
			key=int(input())
			location=binarySearch(array,key)
			if (location!=-1):
				print("The roll no is present at index",location)
			else:
				print("Roll no is not present")

		elif ch==2:
			print("Enter roll no you want to search :")
			key=int(input())
			print("The element is present at index :",fibSearch(array,key,len(array)))
		else:
			break
	print("Exitting Program")

main()