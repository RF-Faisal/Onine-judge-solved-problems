#include<bits/stdc++.h>
using namespace std;

const int MX = 1e5+3;
vector<int> adj[MX];
bitset<MX> vis, dfsvis;

bool cycle = false;
void DFS(int node, stack<int>&ts){
    vis[node] = true;
    dfsvis[node] = true;
    for(int child: adj[node]){
        if(dfsvis[child])
            cycle = true;
        if(!cycle and !vis[child])
            DFS(child, ts);
    }
    dfsvis[node] = false;
    ts.emplace(node);
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin>>n>>m;
    while(m--){
        int a, b; cin>>a>>b;

        adj[a].emplace_back(b);
    }

    stack<int> ts;
    for(int i=1; i<=n; ++i)
        if(!cycle and !vis[i]) DFS(i, ts);

    if(cycle) 
        cout<<"IMPOSSIBLE";
    else{
        while(!ts.empty()){
            cout<<ts.top()<<' ';
            ts.pop();
        }
    }       
}
