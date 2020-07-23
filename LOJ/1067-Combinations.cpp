#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000003;
const int MX = 1000003;

int fact[MX];
void factorial(){
    fact[0] = 1;
    for(int i=1; i<MX; i++)
        fact[i] = 1ll*fact[i-1]*i % MOD; 
}

int BinExpo(int a, int n){
    int res = 1;
    while(n){
        if(n&1) res = 1ll*res*a % MOD;
        a = 1ll*a*a % MOD, n/=2;
    }
    return res;
}

int nCr(int n, int r){
    int de = 1ll*BinExpo(fact[n-r], MOD-2)*BinExpo(fact[r], MOD-2)%MOD;
    return 1ll*fact[n]*de%MOD;
}

int main(){
    ios_base::sync_with_stdio(false); //cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin>>tc;
    factorial();
    for(int cn = 1; cn <= tc; ++cn)
    {   
        int n,r; cin>>n>>r;

        cout<<"Case "<<cn<<": "<<nCr(n, r)<<"\n";
    }
    return 0;
}
