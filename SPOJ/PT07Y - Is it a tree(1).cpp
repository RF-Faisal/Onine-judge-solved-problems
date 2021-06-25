#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/faisal/Documents/debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int MX = 1e4+2;

bool visited[MX];
vector<int> adj[MX];
bool cyclic = false;

void dfs(int node, int parent){
    visited[node] = true;

    for(int child: adj[node]){
        if(child != parent){
            if(!visited[child]) dfs(child, node);
            else cyclic = true;
        }
    }
}
signed main(){
    FIO 
    int n, m; cin>>n>>m;
    
    int u, v; 
    for(int i=0; i<m; ++i){
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(u, 0);

    cout<<(cyclic? "NO\n": "YES\n");
}
