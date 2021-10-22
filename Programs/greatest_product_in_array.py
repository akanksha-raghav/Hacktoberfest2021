""""
Find pair with greatest product in array

Problem Description:

Given an array of n elements, the task is to find the greatest number present in the array such that it is product of two elements of given array. 

Sample Test Case:

 Input :  arr[] = {10, 3, 5, 30, 35}
 
 Output:  30
 
 Explanation: 30 is the product of 10 and 3.
                 
                 
Time Complexity - O(n Log n) 

"""

from math import sqrt
def findGreatest(arr, n):
	# Store occurrences of all elements in hash
	m = dict()
	for i in arr:
		m[i] = m.get(i, 0) + 1

	# Sort the array 
	arr=sorted(arr)
	for i in range(n - 1, 0, -1):
		j = 0
		while(j < i and arr[j] <= sqrt(arr[i])):
			if (arr[i] % arr[j] == 0):
				result = arr[i]//arr[j]
				if (result != arr[j] and (result in m.keys() )and m[result] > 0):
					return arr[i]
				elif (result == arr[j] and (result in m.keys()) and m[result] > 1):
					return arr[i]
			j += 1
	return -1


arr= [17, 2, 1, 15, 30]
n = len(arr)
print(findGreatest(arr, n))
