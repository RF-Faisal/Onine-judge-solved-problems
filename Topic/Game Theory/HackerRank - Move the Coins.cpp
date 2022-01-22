//https://www.hackerrank.com/challenges/move-the-coins/problem
//staircase nim

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int N = 5e4+2;
vector<int> adj[N];
int coin[N], sub_game[N][2];
bool vis[N], parity_tree[N];

int in_time[N], out_time[N], _clock;
void DFS(int node, bool parity){
    in_time[node] = ++_clock;
    vis[node] = true;
    parity_tree[node] = parity;

    for(int child: adj[node]){
        if(!vis[child]){
            DFS(child, !parity);
            sub_game[node][parity] ^= sub_game[child][!parity]; 
            sub_game[node][!parity] ^= sub_game[child][parity]; 
        }
    }
    sub_game[node][1] ^= coin[node];
    out_time[node] = ++_clock;
}
signed main(){
    FIO int n; cin>>n;
    for(int i=1; i<=n; ++i) cin>>coin[i];
    for(int i=1; i<n; ++i){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 1); //level counted starting from 1
    int res = sub_game[1][0];

    int q; cin>>q;
    while(q--){
        int u, v; cin>>u>>v;

        if(in_time[u]<in_time[v] and out_time[v]<out_time[u])
            cout<<"INVALID\n";
        else if(parity_tree[u] != parity_tree[v])
            cout<<(res? "YES": "NO")<<'\n';
        else
            cout<<(res^sub_game[u][0]^sub_game[u][1]? "YES": "NO")<<'\n';
    }
}
