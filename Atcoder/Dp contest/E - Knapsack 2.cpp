#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e9+2;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, W; cin>>N>>W;
    int wei[N], val[N], mx = 0;
    for(int i=0; i<N; ++i) cin>>wei[i]>>val[i], mx += val[i];

    int dp[mx+2]; // dp[value]
    fill(dp, dp+mx+2, INF);
    dp[0] = 0;

    for(int i=0; i<N; ++i)
        for(int j=mx; j>=val[i]; --j)
            dp[j] = min(dp[j], dp[j-val[i]] + wei[i]);
    
    for(int j=mx; j>=0; --j)
        if(dp[j] <= W){
            cout<<j<<'\n';
            break;
        }
}

//can you explain line 17 to 19 
