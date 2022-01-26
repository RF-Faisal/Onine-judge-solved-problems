#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/media/faisal/New Volume/CP/Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int N = 1002;
double dp[N][N];
double p[N];

signed main(){
    FIO TC{
        int n, k; cin>>n>>k;
        for(int i=1; i<=n; ++i)
            cin>>p[i];

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;

        for(int i=1; i<=n; ++i){
            dp[0][i] = dp[0][i-1] * (1-p[i]);
            for(int j=1; j<=i; ++j){
                dp[j][i] = dp[j-1][i-1] * p[i] + dp[j][i-1] * (1-p[i]);
            }
        }

        cout<<fixed<<setprecision(10)<<dp[k][n]<<'\n';
    }
}
