#https://codeforces.com/contest/1363/problem/A
TC = int(input())
for cn in range(TC):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))[:n]

    odd = 0
    for i in a:
        if i%2==1:
            odd += 1
    
    if odd==0 or (x%2==0 and odd==n) or (x==n and odd%2==0):
        print("NO")
    else:
        print("YES")
