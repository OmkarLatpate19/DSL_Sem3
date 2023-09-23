'''Write a Python program to store first year percentage of students in array. 
   Write function for sorting array of floating point numbers in ascending order using 
   a) Selection Sort b) Bubble sort and display top five scores.'''

def selectSort(arr,n):
	for i in range (n):
		min=i
		for j in range (i+1,n):
			if(arr[j]<arr[min]):
				min=j
		temp=arr[i]
		arr[i]=arr[min]
		arr[min]=temp
	print(arr)


def bubbleSort(arr,n):
	i=0
	for i in range(n-1):
		for j in range(0,n-i-1):
			if(arr[j]>arr[j+1]):
				temp=arr[j]
				arr[j]=arr[j+1]
				arr[j+1]=temp
	print(arr)

def topFive(arr):
	init=-1
	print("Marks of top 5 students are:")
	while init>=-5:
		print(arr[init])
		init-=1
	return arr

def main():
	print("How many students in class?")
	n=int(input())
	array=[]
	print("Enter Percentage of students")
	for i in range(n):
		array.append(int(input()))
	print("Percentage of students in class are :",array)
	
	while True:
		print("\n1.Selection Sort\n2.Bubble Sort\n3.Exit")
		ch=int(input("Enter your choice :"))
		
		if ch==1:
			print("Sorted array using selection sort")
			selectSort(array,n)
			print()
			topFive(array)

		elif ch==2:
			print("Sorted array using bubble sort")
			bubbleSort(array,n)
			print()
			topFive(array)
		
		else:
			break
	print("Exitting Program!!!")
main()
	
		