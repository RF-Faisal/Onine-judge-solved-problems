//hint: Fermat's Little Theorem

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn)

const int MOD = 1e9+7;
int bigMod(int a, int n, int M = MOD){
	int res = 1;
	while(n){
		if(n&1) res = a*res % M;
		a = a*a % M, n>>=1;
	}
	return res;
}

void solve(){
	int a, b, c; cin>>a>>b>>c;
	cout<<bigMod(a, bigMod(b, c, MOD-1))<<'\n';
}

signed main(){
	FIO TC solve();
}
