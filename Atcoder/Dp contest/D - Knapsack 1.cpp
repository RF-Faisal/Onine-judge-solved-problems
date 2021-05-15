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

const int MX_n = 102, MX_w = 1e5+2;
int dp[MX_n][MX_w];
int val[MX_n], weight[MX_n];

int knapsack(int nth, int w){
    if(!nth or !w) return 0;

    if(dp[nth][w] != -1) return dp[nth][w];

    if(weight[nth] > w) 
        return dp[nth][w] = knapsack(nth-1, w);    
    return dp[nth][w] = max(val[nth] + knapsack(nth-1, w - weight[nth]), knapsack(nth-1, w));
}

signed main(){
    FIO int n, W; cin>>n>>W;
    for(int i=1; i<=n; ++i) cin>>weight[i]>>val[i];

    for(int i=0; i<MX_n; ++i)
        for(int j=0; j<MX_w; ++j)
            dp[i][j] = -1;    

    cout<<knapsack(n, W)<<'\n';
}
