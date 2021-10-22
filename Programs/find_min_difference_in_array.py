""""
Find minimum difference between any two element in an array by using sort function
                 
Time Complexity - O(n Log n) 
"""

def findMinDiff(arr, n):

    # Sort array in ascending order
    arr = sorted(arr)

    # Initialize difference as infinite
    diff = 10**20

    # Find the min diff by comparing adjacent
    for i in range(n-1):
        if arr[i+1] - arr[i] < diff:
            diff = arr[i+1] - arr[i]

    return diff


arr = [1, 5, 3, 19, 18, 25]
n = len(arr)
print("Minimum difference is " + str(findMinDiff(arr, n)))
