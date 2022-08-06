//https://atcoder.jp/contests/arc145/tasks/arc145_c

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int MX = 4e5+5, MOD = 998244353;
int fact[MX], ifact[MX], inv[MX];

void init(){
    inv[1] = ifact[0] = fact[0] = 1;
    for(int i=2; i<MX; ++i) inv[i] = inv[MOD%i] * (MOD-MOD/i) % MOD;
    for(int i=1; i<MX; ++i) fact[i] = fact[i-1]*i % MOD, ifact[i] = ifact[i-1]*inv[i] % MOD; 
}
int nCr(int n, int r){
    if(r<0 or r>n)return 0;
    return fact[n]*ifact[n-r] % MOD *ifact[r] % MOD;
}
int bigMod(int a, int n){
    int res = 1;
    while(n){
        if(n&1) res = res*a % MOD;
        a = a*a%MOD; 
        n >>= 1;
    }
    return res;
}

/* soln: 
     res = 2^n * Cn * n!
         = 2^n * (n+1)^-1 * nCr(2n, n) * n!
         = 2^n * (2n)!/(n+1)!
*/

void solve(){
    init();
    int n; cin>>n;

    // int ans = bigMod(2, n) * fact[n] % MOD * nCr(2*n, n)% MOD * inv[n+1] % MOD; 
    int ans = bigMod(2, n) * fact[2*n] % MOD * ifact[n+1] % MOD; 
    cout<<ans;
}

signed main(){
    FIO solve();
}
