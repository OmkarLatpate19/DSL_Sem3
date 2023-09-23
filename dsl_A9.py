'''Write a Python program to compute following computation on matrix: 
	a) Addition of two matrices 
	B) Subtraction of two matrices 
	c) Multiplication of two matrices 
	d) Transpose of a matrix'''

mat_A=[]
mat_B=[]
Add=[]
Sub=[]
Multiply=[]
trans=[]

r=int(input("Enter Number of rows in matrix :"))
c=int(input("Enter Number of columns in matrix :"))

def data():
	m=[]
	for i in range(r):
		a=[]
		for j in range(c):
			a.append(int(input("Enter elements for matrix ")))
		m.append(a)
	return m

def display(m):
    for i in range(r):
        for j in range(c):
            print(m[i][j],end=" ")
        print()

def addition(a,b):
	for i in range(len(a)):
		temp_add=[]
		for j in range (len(a[i])):
			result_add=a[i][j]+b[i][j]
			temp_add.append(result_add)
		Add.append(temp_add)
	return Add

def subtraction(a,b):
	for i in range(len(a)):
		temp_sub=[]
		for j in range (len(a[i])):
			result_sub=a[i][j]-b[i][j]
			temp_sub.append(result_sub)
		Sub.append(temp_sub)
	return Sub

def multiplication(m1,m2):
	if (len(m2)!=len(m1[0])):
		print("Multiplication can not be performed !!!")
	for i in range (len(m1)):
		a=[]
		for j in range (len(m2[0])):
			a.append(0)
		Multiply.append(a)
	for i in range (len(m1)):
		for j in range (len(m2[0])):
			for k in range (len(m1[0])):
				Multiply[i][j]+=m1[i][k]*m2[k][j]
	return Multiply

def transpose(a):
	for i in range (len(a)):
		t=[]
		for j in range (len(a[i])):
			t.append(0)
		trans.append(t)
	for i in range (len(a)):
		for j in range (len(a[i])):
			trans[i][j]=a[j][i]
	return trans
	

def main():
	print("Enter elements in Matrix A")
	mat_A=data()
	print("Matrix A :")
	display(mat_A)

	print("Enter elements in Matrix B")
	mat_B=data()
	print("Matrix B :")
	display(mat_B)

	while True:
		print("------MENU------\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n5.Exit\n-------------------")
		ch=int(input("Enter your choice :"))
		
		if ch==1:
			print("Addition of matrices")
			addition(mat_A, mat_B)
			display(Add)
		elif ch==2:
			print("Subtraction of matrices")
			subtraction(mat_A, mat_B)
			display(Sub)
		elif ch==3:
			print("Multiplication of matrices")
			multiplication(mat_A, mat_B)
			display(Multiply)
		elif ch==4:
			print("Transpose of matrix A")
			t1=transpose(mat_A)
			display(t1)
			print("Transpose of matrix B")
			t2=transpose(mat_B)
			display(t2)
		else:
			break
	print("Exitting Program!!!")

main()
			


