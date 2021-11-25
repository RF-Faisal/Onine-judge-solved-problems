/*
ans is M^(K^N)
according to Euler theorem we know 
    a^(p-1) ≡ 1 (mod p) [here a and p are co-prime]

now, 
    let K^N = (p-1)*q + r
    so, K^N ≡ r (mod p-1)

Finally,
    ans = M^r % P [here r = (K^N % (p-1))]
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int BigMod(int a, int n, int MOD){
    int res = 1;
    a %= MOD;
    while(n){
        if(n&1) res = (res*a) % MOD;
        a = (a*a) % MOD, n >>= 1;
    }
    return res;
}
signed main(){
    FIO int M, K, N; cin>>N>>K>>M;
    int p = 998244353;
    
    if(M % p == 0){ //Euler's theorem only works when p is coprime to M
        cout<<0<<'\n'; return 0;
    }

    int r = BigMod(K, N, p-1);
    int ans = BigMod(M, r, p);

    cout<<ans<<'\n'; 
}
