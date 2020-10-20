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

const int MX = 1e5+1;
int happiness[MX][3], dp[MX][3];

int func(int n, int type){
    if(dp[n][type] != 0) return dp[n][type];

    if(func(n-1, (type+1)%3) > func(n-1, (type+2)%3))
        return dp[n][type] = happiness[n][type] + dp[n-1][(type+1)%3];
    return dp[n][type] = happiness[n][type] + dp[n-1][(type+2)%3];
}
signed main(){
    FIO int n; cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>happiness[i][0]>>happiness[i][1]>>happiness[i][2];
    
    dp[1][0] = happiness[1][0];
    dp[1][1] = happiness[1][1];
    dp[1][2] = happiness[1][2];

    cout<<max({func(n, 0), func(n, 1), func(n, 2)});
}
