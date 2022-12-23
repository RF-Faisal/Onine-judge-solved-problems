//https://codeforces.com/gym/103960/problem/H

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

const int N = 10002;
vector<int> adj[N], rev[N];
bitset<N> vis;
int n, m;
int comp[N]; //stores nth node is included to which scc_no

void DFS1(int node, stack<int> &TS){
    vis[node] = true;
    for(int child: adj[node])
        if(!vis[child]) DFS1(child, TS);

    TS.push(node);
}
void DFS2(int node, const int cc_no, vector<int> &vec){
    vis[node] = true;
    comp[node] = cc_no;
    vec.push_back(node);

    for(int child: rev[node])
        if(!vis[child]) DFS2(child, cc_no, vec);
}

auto SCC(){
    vis.reset();
    stack<int> TS;
    for(int i=1; i<=n; ++i)
        if(!vis[i]) DFS1(i, TS);

    //finding the SCCs using TopSort
    vis.reset();
    int cc_no = 1;
    vector<vector<int>> components;
    while(!TS.empty()){
        int idx = TS.top();
        TS.pop();

        if(!vis[idx]){
            vector<int> vec;
            DFS2(idx, cc_no++, vec);
            components.push_back(vec);
        }
    }

    return components;
}

map<int, int> mp, in, out;
bitset<N> vs;

int DFS3(int node){
    // vs[node] = true;
    int child;
    for(int it: adj[node]){
        // debug(node, adj[node]);
        child = mp[it];
        if(child == node) continue;
        ++out[node];

        if(!vs[child]){
            // debug(child);
            vs[child] = true;
            ++in[child];
            DFS3(child);
        }
    }
}
signed main(){
    FIO cin>>n>>m;

    for(int i=1; i<=n; ++i){
        mp[i] = i;
    }
    for(int i=0; i<m; ++i){
        int u, v; cin>>u>>v;
        // --u, --v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    int temp = 0;
    auto res = SCC();
    int sz = res.size(), scc_no = 1;
    if(sz == 1){
        cout<<0;
        return 0;
    }
    //cout<<"No. of SCC: "<<sz<<'\n';
    for(auto x: res){
        //cout<<"SCC no."<<scc_no++<<" includes nodes: ";
        int it = -1;
        for(auto y: x){
            if(it == -1) it = y;
            else ++temp;
            mp[y] = it;
        }
        // debug(x);
        //cout<<'\n';
    }

    for(int i=1; i<=n; ++i){
        if(!vs[mp[i]]){
            // vs[mp[i]] = true;
            DFS3(mp[i]);
        }
    }

    int cr, IN=0, OT=0;
    for(int i=1; i<=n; ++i){
        cr = mp[i];
        if(!in[cr]) ++IN, in[cr]=1;
        if(!out[cr]) ++OT, out[cr]=1;
    }

    cout<<max(IN, OT);
}
