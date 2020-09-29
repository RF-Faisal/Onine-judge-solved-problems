#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int mx = 1003;
bitset<mx> vis;
vector<int> rel[mx];
int money[mx], avg;

bool bfs(int node){
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    int sum = money[node], vis_cnt = 1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // debug(cur);

        for(auto child: rel[cur]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                sum += money[child];
                ++vis_cnt;
            }
        }
    }
    // debug(sum ,vis_cnt);
    return (sum/vis_cnt == avg? 1: 0); 
}
signed main(){
    FIO TC{
        int n, m; cin>>n>>m;
        int sum = 0;
        for(int i=1; i<=n; ++i) cin>>money[i], sum += money[i];

        while(m--){
            int u, v; cin>>u>>v;
            rel[u].push_back(v);
            rel[v].push_back(u);
        }

        cout<<"Case "<<cn<<": ";

        bool blessed = sum%n==0? 1: 0;
        avg = sum/n;

        // debug(rel);
        for(int i=1; i<=n and blessed; ++i)
        {
            if(!vis[i]) blessed = bfs(i);
        }
        cout<<(blessed? "Yes\n": "No\n");

        vis.reset();
        for(int i=0; i<=n; ++i) rel[i].clear();
    }   
}
