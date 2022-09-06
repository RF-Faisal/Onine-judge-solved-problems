#https://codeforces.com/gym/101608/problem/M
import sys
sys.stdin = open('chess.in', 'r') 

tc = int(input())
for i in range(tc):
    n, k = map(int, input().split())
    x = n//(k+1)
    y = n % (k+1)
    lp = x*x*(k+1)

    if(y):
        lp += 2*x*y+y
    
    print(n*n - lp)
