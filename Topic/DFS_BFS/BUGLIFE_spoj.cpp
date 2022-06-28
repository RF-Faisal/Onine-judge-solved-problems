//https://vjudge.net/problem/SPOJ-BUGLIFE
#include "bits/stdc++.h"
using namespace std;
const int MX = 2e3+2;
 
vector<int> adj[MX];
bool visited[MX], col[MX];
 
bool isBipartite(int node, bool c){
    visited[node] = true;
    col[node] = c;
 
    for(auto child: adj[node]){
        if(!visited[child]){
            bool res = isBipartite(child, 1^c);
            if(!res)
                return false;
        }
        else if(col[node] == col[child]){
            return false;
        }
    }
    return true;
}
 
int main(){
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn){
        int n, m, a, b; cin>>n>>m;
 
        for(int i=1; i<=n; ++i) adj[i].clear(), visited[i] = false;
        for(int i=1; i<=m; ++i){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
 
        bool res = true, c = true;
        for(int i=1; i<=n and res; ++i){
            if(!visited[i]){
                res = isBipartite(i, c);
                // cout<<"a"<<i<<"b"<<" "<<res<<" ";
            }
        }
        cout<<"Scenario #"<<cn<<":\n";
        cout<<(res? "No suspicious bugs found!\n": "Suspicious bugs found!\n");
    }
}
