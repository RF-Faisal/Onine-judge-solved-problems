#include<bits/stdc++.h>
using namespace std;
 
#define SIZE 10010
#define MOD 10000007
 
long long a, b, c, d, e, f;
long long dp[SIZE];
 
long long fn(long long n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
 
    if(dp[n]!= -1) return dp[n];
    else{
        dp[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%MOD;
        return dp[n];
    }
 
}
int main() {
    long long n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
    memset(dp,-1,SIZE*sizeof(dp[0]));
        scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n)%MOD);
    }
    return 0;
}
