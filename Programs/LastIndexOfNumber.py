## first Read input then Print output 

def lastIndex(arr, x):
    l = len(arr)
    if l == 0:
        return -1
    
    smallerList = arr[1:]
    smallerListOutput = lastIndex(smallerList, x)
    if smallerListOutput != -1:
        return smallerListOutput +1
    else:
        if arr[0] == x:
            return 0
        else:
            return -1
from sys import setrecursionlimit
setrecursionlimit(11000)
n=int(input())
a=list(int(i) for i in input().strip().split(' '))
x=int(input())
print(lastIndex(a,x))
