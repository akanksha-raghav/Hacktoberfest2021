'''
A triangular number is formed by the addition of consecutive integers starting with 1. For example,
1 + 2 = 3
1 + 2 + 3 = 6
1 + 2 + 3 + 4 = 10
1 + 2 + 3 + 4 + 5 = 15

Thus, 3, 6, 10, 15, are triangular numbers.
Write a program in Python to display all the triangular numbers from 3 to n, taking the value of n as an input.
'''

#Function Starts-----------------------------
def TriangularSeries(max : int) -> None:
	
	print("3",end= '')
	#n = 2 ---> sum = 3,
	#n = 3 ---> sum = 6,
	#n = 4 ---> sum = 10, ...
	n = 3
	#Starting With 6 As 3 Already Printed
	while True:
		sum = int( (n * (n+1)) /2 )
		if sum > max:
			break
		print(",",sum,end = '')
		n += 1
	
	print()
#Function Ends-----------------------------


num = int(input("Enter The Upper Limit For Triangular Series:"))

if num < 3:
	print("The Series Starts At 3.\nHence Input Should Be Greater Than Or Equal To 3.")

else:
	TriangularSeries(num)
	