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

const int mx_n = 102, mx_w = 1e5+2;
int dp[mx_n][mx_w];

signed main(){
    FIO int n, w; cin>>n>>w;
    int wei[n+1], val[n+1];
    for(int i=1; i<=n; ++i) cin>>wei[i]>>val[i];

    for(int i=0; i<=n; ++i) dp[i][0] = 0;
    for(int i=0; i<=w; ++i) dp[0][i] = 0;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=w; ++j){
            if(j - wei[i] >= 0)
                dp[i][j] = max(dp[i-1][j], val[i] + dp[i-1][j-wei[i]]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<'\n';
}
