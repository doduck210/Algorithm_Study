#https://www.acmicpc.net/problem/1920
import sys

#inputs
n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
m=int(sys.stdin.readline())
M=list(map(int,sys.stdin.readline().split()))
a.sort()

#search
def binary(l,begin,end):
    if begin>end:
        return 0
    m=(begin+end)//2
    if l==a[m] :
        return 1
    elif l<a[m] :
        return binary(l,begin,m-1)
    else:
        return binary(l,m+1,end)

for i in M:
    print(binary(i,0,n-1))