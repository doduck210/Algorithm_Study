#https://www.acmicpc.net/problem/1655
import heapq
import sys

left, right = [], [] #left:max, right:min
n=int(sys.stdin.readline())

for i in range(n):
    num=int(sys.stdin.readline())
    if(len(left))<=(len(right)):
        heapq.heappush(left,(-num,num))
    else:
        heapq.heappush(right,num)
    
    if right and left[0][1] > right[0]: #[0]means root [1] means its value
        leftTmp=heapq.heappop(left)[1]
        rightTmp=heapq.heappop(right)
        heapq.heappush(left,(-rightTmp,rightTmp))
        heapq.heappush(right,leftTmp)

    print(left[0][1])