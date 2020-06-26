import math 
while True:
    n = int(input())
    if n==0 : break
    sq = (int)(math.sqrt(n))
    if sq*sq == n:
        print("Yes")
    else :
        print("No")
