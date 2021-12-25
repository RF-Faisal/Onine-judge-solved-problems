//https://codeforces.com/contest/126/problem/B

#include<bits/stdc++.h>
using  namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif

#define int long long

const int base = 31, MX = 1e6+2, MOD = 1e9+9;
int base_pow[MX];

int copmpute_hash(string &s){
    int n = s.size();
    int ret = 0;
    for(int i=0; i<n; ++i){
        ret *= base;
        ret %= MOD;
        ret += (s[i] - 'a' + 1);
        ret %= MOD;
    }
    return ret;
}

int hash_char(char ch, int val, int pwr){
    int ret = ch - 'a' + 1; 
    ret = (ret * base_pow[pwr]) % MOD;
    ret += val;

    return ret % MOD;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str; cin>>str;
    int n = str.size();  
      
    base_pow[0] = 1;
    for(int i=1; i<=n; ++i){
        base_pow[i] = (base_pow[i-1] * base) % MOD;
    }

    int pre_hash[n+1]; pre_hash[n] = 0;
    for(int i=n-1; i>=0; --i){
        pre_hash[i] = hash_char(str[i], pre_hash[i+1], n-i-1);  
    }    

    vector<int> found_at;
    for(int i=1; i<n; ++i){
        int lt = ((pre_hash[0] - pre_hash[i]) + MOD) % MOD;
        int rt = ((pre_hash[n-i] - pre_hash[n] + MOD) * base_pow[n-i]) % MOD;

        debug(i, lt, rt);
        if(lt == rt) found_at.push_back(i);
    }

    debug(found_at);
    if(found_at.empty()) cout<<"Just a legend";
    else{
        for(auto itr = found_at.rbegin(); itr != found_at.rend() and *itr!=0; ++itr){
            debug(*itr);
            int found_str = (pre_hash[0] - pre_hash[*itr] + MOD) % MOD;

            for(int i=1; i+*itr<n; ++i){
                int chk_str = (((pre_hash[i] - pre_hash[i+*itr] + MOD) %MOD) * base_pow[i]) % MOD;
                debug(i, found_str, chk_str);
                if(chk_str == found_str){
                    for(int j=0; j<*itr; ++j) cout<<str[j];
                    return 0;
                } 
            }
        }
        cout<<"Just a legend";
    }
}
