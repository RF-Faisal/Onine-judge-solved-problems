//https://www.spoj.com/status/ns=29046332

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/media/faisal/New Volume/CP/Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int MX = 1e6+2, MOD = 1e9+7, prime = 53;
int pre[MX], inv[MX];

int power(int a, int n, int mod=MOD){
    int res = 1;
    while(n){
        if(n&1) res = (res * a) % mod;
        a = (a*a) % mod; n >>= 1;
    }
    return res;
}

int getHash(string s){
    int base = prime;
    int res = 0;
    for(int i=0; i<s.size(); ++i){
        res = (res + (s[i]-'a'+1) * base) % MOD;
        base = (base * prime) % MOD;  
    }
    return res;
}
void init(string s){
    int base = prime;

    pre[0] = s[0]-'a'+1;
    inv[0] = 1;
    for(int i=1; i<s.size(); ++i){
        pre[i] = (pre[i-1] + (s[i]-'a'+1) * base) % MOD;
        inv[i] = power(base, MOD-2);
        base = (base * prime) % MOD;
    }
}
signed main(){
    int n; 
    string niddle, haystack;
    while(cin>>n){
        cin>>niddle;
        cin>>haystack;
        
        int niddleHash = getHash(niddle); 
        init(haystack);

        bool in = false;
        int m = haystack.size();
        for(int i=0; i<m-n+1; ++i){
            int subStrHash = pre[i+n-1];
            subStrHash -= (i? pre[i-1]: 0);
            subStrHash = (subStrHash + MOD) % MOD; 
            subStrHash = (subStrHash * (i? inv[i-1]: 1)) % MOD;

            if(subStrHash == niddleHash){
                in = true;
                cout<<i<<'\n';
            } 
            // debug(niddleHash, subStrHash, i);
            // debug(n, niddle, haystack);
        }

    }
}
