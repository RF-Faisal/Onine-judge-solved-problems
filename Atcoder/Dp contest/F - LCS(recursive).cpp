#include<bits/stdc++.h>
using namespace std;

const int MX=3002;
int dp[MX][MX];
string s, t; 
int n, m;

int LCS(int id1, int id2){
    if(id1<1 or id2<1) return 0;
    if(dp[id1][id2] != -1) return dp[id1][id2];
    
    if(s[id1-1]==t[id2-1]) return dp[id1][id2] = 1 + LCS(id1-1, id2-1);
    return dp[id1][id2] = max(LCS(id1-1, id2), LCS(id1, id2-1));
}
void printLCS(int id1, int id2, string ans=""){
    if(ans.size()==dp[n][m]){
        cout<<ans<<'\n';
        return;
    }
    
    if(s[id1-1]==t[id2-1]){
        printLCS(id1-1, id2-1, s[id1-1]+ans);
        return;
    }
    
    int l = dp[id1-1][id2];
    int r = dp[id1][id2-1];
    if(l < r) printLCS(id1, id2-1, ans);
    else printLCS(id1-1, id2, ans);
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>s>>t;
    n = s.size(), m = t.size();
    
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<MX; ++i) dp[0][i]=dp[i][0]=0;
    
    LCS(n, m);
    printLCS(n, m);
}   
