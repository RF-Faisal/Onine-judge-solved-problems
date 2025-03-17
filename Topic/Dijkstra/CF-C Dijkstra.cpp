// https://codeforces.com/contest/20/problem/C

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
const int MX = 2e5+2, INF = 1e18+2;

class Node{
public:
    int uu, ww;
    
    Node(int uu, int ww){
        this->uu = uu;
        this->ww = ww;
    }
    bool operator <(const Node &rt) const{
        return ww > rt.ww;
    }
};

vector<int> adj[MX], wei[MX];
void Dijkstra(int src, int n){
    vector<int> dist(n+1, INF), par(n+1, -1);
    dist[src] = 0;
    par[src] = -1;

    priority_queue<Node> PQ;
    PQ.push({1, 0});

    while(!PQ.empty()){
        Node temp = PQ.top();
        PQ.pop();

        int u = temp.uu;
        for(int i=0; i<adj[u].size(); ++i){
            int v = adj[u][i];
            int c = wei[u][i];

            if(dist[v] > dist[u] + c){
                dist[v] = dist[u] + c;
                par[v] = u;
                PQ.push({v, dist[v]});
            }
        }
    }
    
    vector<int> path;
    if(par[n] == -1){
        cout<<"-1\n"; return;
    }
    path.push_back(n);

    int cur = n;
    while(par[cur] != -1){
        path.push_back(par[cur]);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    
    for(auto it: path){
        cout<<it<<' ';
    }
}
signed main(){
    FIO int v, e; cin>>v>>e;
    for(int i=0; i<e; ++i){
        int U, V, W; cin>>U>>V>>W;
        
        adj[U].push_back(V);
        adj[V].push_back(U);
        wei[U].push_back(W);
        wei[V].push_back(W);     
    }

    Dijkstra(1, v); 
}
