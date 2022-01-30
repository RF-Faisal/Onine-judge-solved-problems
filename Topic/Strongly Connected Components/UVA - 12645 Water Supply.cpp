#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "D:\CP\Debugger.h"
// #else 
// #define debug(x...)
// #endif
// #define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int N = 1002;
vector<int> adj[N], rev[N];
bitset<N>vis;
int n, m; 
int comp[N];

void DFS1(int node, stack<int>&TS){
    vis[node] = true;
    for(int child: adj[node])
        if(!vis[child]) DFS1(child, TS);
    
    TS.push(node);
}
void DFS2(int node, const int scc_no){
    vis[node] = true;
    comp[node] = scc_no;
    
    for(int child: rev[node])
        if(!vis[child]) DFS2(child, scc_no);
}

int SCC(){
    vis.reset();
    stack<int> TS;
    for(int i=0; i<=n; ++i)
        if(!vis[i]) DFS1(i, TS);

    vis.reset();
    int scc_no = 0;
    while(!TS.empty()){
        int idx = TS.top();
        TS.pop();

        if(!vis[idx]) DFS2(idx, ++scc_no);
    }
    return scc_no;
}

signed main(){
    FIO while(cin>>n>>m){
        vector<pair<int, int>> edges(m);
        for(int i=0; i<m; ++i){
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            rev[v].push_back(u); 

            edges[i] = {u, v};
        }

        int scc_cnt = SCC();
        vector<int> indeg(scc_cnt+1);
        for(auto it: edges){
            int u = it.first;
            int v = it.second;

            if(comp[u] != comp[v])
                ++indeg[comp[v]];
        }

        int pipes = 0;
        for(int i=1; i<=scc_cnt; ++i)
            if(!indeg[i]) ++pipes;
        if(!indeg[comp[0]]) --pipes;

        cout<<pipes<<'\n';

        for(int i=0; i<=n; ++i){
            adj[i].clear();
            rev[i].clear();
        }
    }
}
