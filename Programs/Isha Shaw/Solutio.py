class Solution(object):
    def longestOnes(self, A, k):
        i = 0
        for j in xrange(len(A)):
            k -= A[j] == 0
            if k < 0:
                k += A[i] == 0
                i += 1
        return j - i + 1
