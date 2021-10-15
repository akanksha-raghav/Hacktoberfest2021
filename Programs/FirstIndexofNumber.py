# find first index of number by using recusrion

def firstIndex(arr, x):
    l = len(arr)
    if l == 0:
        return -1
    
    if arr[0] == x:
        return 0
    
    smallerList = arr[1:]
    smallerListOutput = firstIndex(smallerList, x)
    if smallerListOutput == -1:
        return -1
    else:
        return smallerListOutput + 1

# Main
from sys import setrecursionlimit
setrecursionlimit(11000)
n=int(input())
arr=list(int(i) for i in input().strip().split(' '))
x=int(input())
print(firstIndex(arr, x))
