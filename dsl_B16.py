'''Write a Python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.'''

def quickSort(arr,left,right):
	if left<right:
		pos=partition(arr,left,right)
		quickSort(arr,left,pos-1)
		quickSort(arr,pos+1,right)

def partition(arr,left,right):
	i=left+1
	j=right
	pivot=arr[left]
	while i<j:
		while arr[i]<pivot:
			i+=1
		while arr[j]>=pivot:
			j-=1
		if i<j:
			arr[i],arr[j]=arr[j],arr[i]
	if i>j:
		arr[i],arr[left]=arr[left],arr[i]
	return j

print("How many student in class?")
n=int(input())
array=[]
i=0
print("Enter percentage of students")
for i in range(n):
	array.append(float(input()))
print("Percentage of students in class are : ",array)

quickSort(array,0,n-1)
print("Sorted array is :",array)