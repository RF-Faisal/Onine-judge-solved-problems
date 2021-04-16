#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD =  1e9+7;

int bin_expo(int a, int n, int mod = MOD){
	int res = 1; 
	while(n){
		if(n&1) res = ((__int128)res*a) % mod;
		a = ((__int128)a*a)%mod, n >>= 1;
	}
	return res;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tc; cin>>tc;
	while(tc--){
		int A, B, N; cin>>A>>B>>N;
		if(B>A) swap(A, B);
		
		if(A==B){
			cout<<(bin_expo(A%MOD, N) + bin_expo(B%MOD,N))%MOD<<'\n';
		}
		else{
			int d = bin_expo(A%(A-B), N, (A-B)) + bin_expo(B%(A-B), N, (A-B)); //(A-B) diye mod korchi hudai
			cout<<__gcd(d, (A-B))%MOD<<'\n';
		}
	}
}
