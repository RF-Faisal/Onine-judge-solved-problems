#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[501][501];
int rec(int br, int stp){
    //base case
    if(br == 0) return 1;
    if(stp == 0) return 0;
    //why base case works? 
    //stp == 0 will reach before than br==0 most of the cases.
    //br==0 will work only when line:19 makes br==stp,
    //and when br==stp only 1 step possible

    if(dp[br][stp] != -1) 
        return dp[br][stp];

    dp[br][stp] = rec(br, stp-1);
    if(br>=stp) dp[br][stp] += rec(br-stp, stp-1);

    return dp[br][stp]; 
}

signed main(){
    int n; cin>>n;
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)
            dp[i][j] = -1;

    cout<<rec(n, n-1);
}
