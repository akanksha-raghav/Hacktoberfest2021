'''
An Evil number is a positive whole number which has even number of 1's in its binary equivalent. Example: Binary equivalent of 9 is 1001, which contains even number of 1's. A few evil numbers are 3, 5, 6, 9…. Design a program to accept a positive whole number and find the binary equivalent of the number and count the number of 1's in it and display whether it is a Evil number or not with an appropriate message. Output the result in format given below:

Example 1
Input: 15
Binary Equivalent: 1111
No. of 1's: 4
Output: Evil Number

Example 2
Input: 26
Binary Equivalent: 11010
No. of 1's: 3
Output: Not an Evil Number
'''

#bin() Is A Method In Python To Convert
#Num Into Binary
#But I Will Be Using Custom Binary Function

#Custom Binary Function----------------------
def Bin(num : int)-> int:
	mun_nib = ''
	
	if num == 0:
		return 0
	
	while num > 0:
		n = num % 2
		mun_nib += str(n)
		num //= 2 #Floor Division
		
	bin_num = mun_nib[::-1] #Reversing String
	return int(bin_num)
#Function Ends-------------------------------

#Function Starts-----------------------------
def isEvil(num : int) -> None:
	
	bin = str(Bin(num))
	print("Binary Equivalent:",bin)
	
	ones = bin.count('1')
	print("No. Of 1's:",ones,end= ' ')
	
	if ones % 2: #0 -> False; 1 -> True
		print(f"(Odd)\n{num= }, Is Not An Evil Number")
	else: 
		print(f"(Even)\n{num= }, Is An Evil Number")
#Function Ends-----------------------------

num = int(input("Enter A Number To Check:"))
if num >= 0:
	isEvil(num)
else:
	print('Incorrect Input. Try Again.')