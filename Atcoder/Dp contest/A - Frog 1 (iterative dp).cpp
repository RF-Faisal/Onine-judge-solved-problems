#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/faisal/Documents/debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

signed main(){
    FIO int n; cin>>n;
    int h[n]; for(int &i: h) cin>>i;

    int dp[n]; 
    dp[0] = 0; dp[1] = abs(h[1] - h[0]);

    for(int i=2; i<n; ++i){
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    cout<<dp[n-1]<<'\n';
}
