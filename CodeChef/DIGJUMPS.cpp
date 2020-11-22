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
const int INF = 1e9;

signed main(){
    FIO string s; cin>>s;
    int n = s.size();
    int dp[n], str[n];

    for(int i=0; i<n; ++i) dp[i] = INF;
    dp[n-1] = 0;

    int mp[10];
    for(int i=0; i<10; ++i) mp[i] = INF;
    mp[s[n-1] - '0'] = 0;

    for(int i=0; i<21; ++i){
        for(int j=0; j<n; ++j){
            if(dp[j] == i){
                if(j!=0) dp[j-1] = min(dp[j-1], i+1);
                if(j<n-1) dp[j+1] = min(dp[j+1], i+1);
            }
            if(j != 0) dp[j-1] = min(dp[j-1], dp[j] + 1), mp[s[j-1] - '0'] = min(mp[s[j-1] - '0'],dp[j-1]);
            if(j < n-1) dp[j+1] = min(dp[j+1], dp[j] + 1), mp[s[j+1] - '0'] = min(mp[s[j+1] - '0'], dp[j+1]);
        }
        for(int j=0; j<n; ++j){
            if(mp[s[j] - '0'] != INF) dp[j] = min(dp[j], mp[s[j] - '0'] + 1);
        }
    }
    // for(int i=0; i<n; ++i) cout<<dp[i]<<' ';
    cout<<dp[0];
}
