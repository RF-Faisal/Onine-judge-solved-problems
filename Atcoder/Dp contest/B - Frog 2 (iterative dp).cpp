#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
const int MX = 2e9+10;

signed main(){
    FIO int n, k; cin>>n>>k;

    int dp[n], h[n]; 
    for(int i=0; i<n; ++i) cin>>h[i], dp[i] = MX;
    
    dp[0] = 0;
    for(int i=0; i<n-1; ++i)
        for(int j=1; j<=k and j+i<n; ++j)
            dp[i+j] = min(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
        

    cout<<dp[n-1]<<'\n';
}   
