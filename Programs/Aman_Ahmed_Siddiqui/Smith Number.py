'''
A Smith number is a composite number, whose sum of the digits is equal to the sum of its prime factors. For example:
4, 22, 27, 58, 85, 94, 121 ………. are Smith numbers.

Write a program in Python to enter a number and check whether it is a Smith number or not.

Sample Input: 666
Sum of the digits: 6 + 6 + 6 = 18
Prime factors are: 2, 3, 3, 37
Sum of the digits of the prime factors: 2 + 3 + 3 + (3 + 7) = 18
Thus, 666 is a Smith Number.
'''

#Function Starts-----------------------------
def Factors(num : int) -> list:
	
	i = 2
	facts = []
	
	while  num > 1:
		if num % i == 0:
			facts.append(i)
			num = num // i
		else:
			i += 1
			
	return facts
#Function Ends-------------------------------


#Function Starts-----------------------------
def DigitsSum(num : int) -> int:
	
	sum = 0
	while num > 0:
		sum += (num % 10)
		num //= 10
	
	return sum
#Function Ends-------------------------------
	
	
#Function Starts-----------------------------
def isSmith(num : int) -> None:
	
	factstr = ''
	factors = Factors(num)
	
	for each in factors:
		factstr += str(each)
	
	facts_sum = DigitsSum( int(factstr) )
	digit_sum = DigitsSum( num )
	
	print(f"Sum Of Digits Of {num}: {digit_sum}")
	print("Prime Factors Are:",factors)
	print("Sum Of Digits Of Prime Factors:",facts_sum)
	
	if facts_sum == digit_sum:
		print(f"Thus, {num} Is A Smith Number.")
	else:
		print(f"{num} Is Not A Smith Number.")
#Function Ends-------------------------------


num = int(input("Enter Number To Check:"))
isSmith(num)
