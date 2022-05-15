#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int MX = 1e6+4, MOD = 1e9+7;
int hsh[MX], hsh_r[MX], P = 31;
int len;

int power(int a, int n){
    int res = 1; 
    while(n){
        if(n&1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        n >>= 1;
    }
    return res;
}

//checks two substrs: [l1, r1] and [l2, r2] are equal or not
bool chk(int l1, int r1, int l2, int r2){ 
    int i = l2-l1;

    int H1 = (((hsh[r1]-hsh[l1-1]+MOD)%MOD) * power(P, i)) % MOD;
    int H2 = (hsh[r2]-hsh[l2-1] + MOD) % MOD;

    return H1==H2;
}

//checks palindrome
bool isPal(int l, int r){
    int l1 = l, r1 = r;
    int l2 = len-r+1, r2 = len-l+1;

    if(l1 < l2){
        int dif = l2-l1;

        int H1 = (((hsh[r1]-hsh[l1-1]+MOD)%MOD) * power(P, dif)) % MOD;
        int H2 = (hsh_r[r2]-hsh_r[l2-1] + MOD) % MOD;

        return H1==H2;
    }
    else{
        int dif = l1-l2;

        int H1 = (hsh[r1]-hsh[l1-1] + MOD) % MOD;
        int H2 = (((hsh_r[r2]-hsh_r[l2-1]+MOD)%MOD) * power(P, dif)) % MOD;

        return H1==H2;
    }
}

signed main(){
    FIO 
    int n, q; cin>>n>>q;
    string str; cin>>str;
    string s = str; 
    reverse(s.begin(), s.end());

    len = n;

    int base = 1;
    for(int i=0; i<n; ++i){
        hsh[i+1] = (hsh[i] + (str[i]-'a') * base) % MOD;
        hsh_r[i+1] = (hsh_r[i] + (s[i]-'a') * base) % MOD;
        base = (base*P) % MOD;
    }

    while(q--){
        int l, r; cin>>l>>r;

        bool putata = true;
        if(isPal(l, r) or (isPal(l+1, r) and isPal(l, r-1)))
            putata = false;
        else if((r-l)&1)
            putata = false;

        cout<<(putata? "Putata\n": "Budada\n");
    }
}
