#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[20][20], half, n, m, k, ans = 0;

map<int, int> mp[20][20];
void go_down_right(int x, int y, int val){
	val ^= a[x][y];
	if(x+y == half){
		++mp[x][y][val];
		return;
	}

	if(x+1 < n) go_down_right(x+1, y, val);
	if(y+1 < m) go_down_right(x, y+1, val);
}
void go_up_left(int x, int y, int val){
	if(x+y == half){//covered the other half
		ans += mp[x][y][k^val];
		return;
	}
	val ^= a[x][y];
	if(x > 0) go_up_left(x-1, y, val);
	if(y > 0) go_up_left(x, y-1, val);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin>>a[i][j];

	half = (n + m - 2) / 2;

	go_down_right(0, 0, 0);
	go_up_left(n-1, m-1, 0);

	cout<<ans;
}
