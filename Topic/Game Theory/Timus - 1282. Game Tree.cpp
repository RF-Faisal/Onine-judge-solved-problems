#include <bits/stdc++.h>
using namespace std;

const int N = 1007;
vector<int> adj[N];
string res[N];
bool vis[N], parity[N];

void DFS(int node){
	vis[node] = true;
	if(res[node] != "-2") return;
	
	int win = 0, lose = 0, draw = 0;
	for(auto child: adj[node]){
		if(vis[child]) continue;
		
		parity[child] = !parity[node];
		DFS(child);
		if(res[child] == "+1") ++win;
		else if(res[child] == "-1") ++lose;
		else ++draw;
	}

	if(parity[node]){
		if(win) res[node] = "+1";
		else if(draw) res[node] = "0";
		else res[node] = "-1";
	}else{
		if(lose) res[node] = "-1";
		else if(draw) res[node] = "0";
		else res[node] = "+1";
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin>>n;

	for(int i=0; i<=n; ++i) res[i] = "-2";

	for(int v=2; v<=n; ++v){
		char type; int u;
		cin>>type>>u;

		adj[u].push_back(v);
		adj[v].push_back(u);

		if(type == 'L'){
			string r; cin>>r;
			res[v] = r;
		}
	}

	parity[1] = true;
	DFS(1);
	cout<<res[1];
}
