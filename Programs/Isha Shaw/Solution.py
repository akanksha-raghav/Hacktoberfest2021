
def longestOnes(A, k):
        i = 0
        for j in xrange(len(A)):
            k -= A[j] == 0
            if k < 0:
                k += A[i] == 0
                i += 1
        return j - i + 1
 
# Driver code
arr = [1, 1, 0, 0, 1, 0, 1,
             0, 1, 1, 1, 1]
k = int(input(Number of k))
print(getMaxLength(arr, k))
