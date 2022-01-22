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

const int N = 102;
int n, ban[2*N][N];
int dp[2*N][N];

int func(int r, int c){
    if(c<1 or c>r) return 0;
    if(r==1) return ban[1][1];
    if(dp[r][c] != -1) return dp[r][c];

    int cur = 0;
    if(r>n)
        cur = max(func(r-1, c), func(r-1, c+1));
    else 
        cur = max(func(r-1, c-1), func(r-1, c));
    return dp[r][c] = ban[r][c] + cur;
}

signed main(){
    FIO TC{
        cin>>n;

        for(int i=1; i<=n; ++i) //top-half
            for(int j=1; j<=i; ++j)
                cin>>ban[i][j];
        for(int i=n+1; i<2*n; ++i) //down-half
            for(int j=1; j+i<=2*n; ++j)
                cin>>ban[i][j];

        memset(dp, -1, sizeof dp);
        cout<<"Case "<<cn<<": "<<func(2*n-1, 1)<<'\n';
    }
}
