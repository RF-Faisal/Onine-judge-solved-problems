#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+2;
int dp[mx], hi[mx];

int func(int n){
        if(n == 0) return 0;
        if(n == 1) return dp[1];
        if(dp[n] != -1) return dp[n];

        return dp[n] = min(func(n-1) + abs(hi[n-1] - hi[n]), func(n-2) + abs(hi[n] - hi[n-2]));
}

signed main(){
        int n; cin>>n;
        for(int i=0; i<n; ++i) cin>>hi[i];

        memset(dp, -1, sizeof dp);
        dp[0] = 0, dp[1] = abs(hi[1] - hi[0]);
        
        cout<<func(n-1);
}
