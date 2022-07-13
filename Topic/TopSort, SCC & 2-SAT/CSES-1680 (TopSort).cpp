/*
problem link: https://cses.fi/problemset/task/1680/

Soln idea: Lets say that I have a sequence of node and if I reach a particular node A then that sequence ensures that
distance of node A up to that point is maximum from root node. If I go further in the sequence after crossing A,
then distance of A from root node will not change. In this way I just need to update the distance of child nodes of A once. 
That is right when we reach A.

how do we get that Sequence? -Topological sorting.
ref: https://discuss.codechef.com/t/help-needed-cses-longest-flight-route-graph-problem-11/74000/20
*/

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
 
const int MX = 1e5+3;
vector<int> adj[MX];
bitset<MX> vis;
 
void DFS(int node, stack<int> &TS){
    vis[node] = true;
    for(int child: adj[node])
        if(!vis[child])
            DFS(child, TS); 
 
    TS.emplace(node);
}
void solve(){
    int n, m; cin>>n>>m;
    while(m--){
        int a, b; cin>>a>>b;
        adj[a].emplace_back(b);
    }   
    stack<int> TS;
    DFS(1, TS);
 
    if(!vis[n]) 
        cout<<"IMPOSSIBLE";
    else{
        int prev[n+1] = {}, dis[n+1] = {};
        dis[1] = 1;
        while(!TS.empty()){
            int node = TS.top(); TS.pop();
            for(int child: adj[node]){
                if(dis[node]+1 > dis[child]){
                    dis[child] = dis[node]+1;
                    prev[child] = node;
                }
            }
        }
 
        cout<<dis[n]<<'\n';
        stack<int> res;
        int cur = n;
        while(cur != 1){
            res.emplace(cur);
            cur = prev[cur];
        }res.emplace(1);
        while(!res.empty()){
            cout<<res.top()<<' ';
            res.pop();
        }
    }
}
signed main(){
    FIO solve();
}
