#include<bits/stdc++.h>
using namespace std;

string s;
int dp[101][101];

int is_palindrome(int st, int ed){
    if(st>ed) return 0;

    if(dp[st][ed] != -1) return dp[st][ed];

    if(s[st] == s[ed]) 
        return dp[st][ed] = is_palindrome(st+1, ed-1);
    return dp[st][ed] = min(is_palindrome(st+1, ed)+1, is_palindrome(st, ed-1)+1);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn)
    {
        cin>>s;
        int n = s.size();

        for(int i=0; i<=n; ++i)
            for(int j=0; j<=n; ++j)
                dp[i][j] = -1;

        cout<<"Case "<<cn<<": "<<is_palindrome(0, n-1)<<'\n';
    }
}
