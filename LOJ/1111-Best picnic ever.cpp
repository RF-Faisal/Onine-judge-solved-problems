#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int people = 101, city = 1001, roadss = 10001;

bool visited[city][city]; // nth city is visited by kth man
vector<int> road[city];

void dfs(int node, int par)
{
    visited[node][par] = true;

    for(auto i: road[node]){
        if(!visited[i][par]){
            dfs(i, par);
        }
    }
}
signed main(){
    FIO TC{
        int k, n, m, var, u, v; cin>>k>>n>>m; //k = people, n = city, m = road

        memset(visited, false, sizeof(visited));
        for(auto &j: road)
            j.clear();

        vector<int> parent;
        for(int i=0; i<k; ++i){
            cin>>var; parent.push_back(var);
        }
        
        for(int i=0; i<m; ++i){
            cin>>u>>v;
            road[u].push_back(v);
        }
        
        for(int i=0; i<k; ++i){            
            dfs(parent[i], parent[i]);
        }
        
        int res = 0;
        for(int i=0; i<city; ++i){
            int ans = 0;
            for(int j=0; j<k; ++j){
                ans += visited[i][parent[j]];
            }
            if(ans == k) {
                res++;
            }
        }
        cout<<"Case "<<cn<<": "<<res<<"\n";
    }   
}