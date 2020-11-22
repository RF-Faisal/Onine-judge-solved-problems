#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

unordered_map<int, int> dp;
int func(int n){
    if(dp[n] != 0) return dp[n];
    if(n/2 + n/3 + n/4 > n) 
        return dp[n] = func(n/2) + func(n/3) + func(n/4);
    return dp[n] = n;
}

signed main(){
    int n;
    while(cin>>n){   
        cout<<func(n)<<'\n';
    }   
}
