#include<bits/stdc++.h>
using namespace std;

const int MX = 3003;
int dp[MX][MX];
string s, t; 

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>s>>t;
	
	int n = s.size(), m = t.size();
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=m; ++j){
			if(i==0 or j==0) dp[i][j] = 0;
			else if(s[i-1]==t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i = n, j = m;
	vector<char> res;
	while(i and j){
		if(dp[i][j] == dp[i][j-1])
			--j;
		else if(dp[i][j] == dp[i-1][j])
			--i;
		else {
			res.push_back(s[i-1]);
			--i, --j;
		}
	}
	for(auto it=res.rbegin(); it != res.rend(); ++it)
		cout<<*it;
}
