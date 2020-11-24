#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
const int INF = 1e9;

signed main(){
    FIO int n, x; cin>>n>>x;
    int coins[n]; for(int &i: coins) cin>>i;

    int dp[x+2];
    for(int i=0; i<x+2; ++i) dp[i] = INF;
    // memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    // cout<<dp[2]<<' ';
    for(int i=1; i<=x+1; ++i){
        for(int j=0; j<n; ++j){
            if(i - coins[j] >= 0)
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
        // cout<<dp[i]<<' ';
    }    
    cout<<(dp[x] == INF? -1: dp[x]);
}
