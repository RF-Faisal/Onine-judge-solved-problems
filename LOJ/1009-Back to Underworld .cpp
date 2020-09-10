#include <bits/stdc++.h>
using namespace std;

const int mx = 2e4+1;
bool visited[mx];
set<int> bipartite[2];
vector<int> adj[mx], parent;

int dfs(int node, bool col)
{
    visited[node] = true;
    bipartite[col].insert(node);

    for(auto child: adj[node]){
        if(!visited[child])
            dfs(child, !col);
    }
    return max(bipartite[0].size(), bipartite[1].size());
}
signed main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int tc; scanf("%d", &tc); 
    for(int cn=1; cn<=tc; ++cn) 
    {
        int n, u, v; scanf("%d", &n);

        memset(visited, false, sizeof visited);
        for(int i=0; i<mx; ++i) adj[i].clear();
        parent.clear();

        for(int i=0; i<n; ++i){
            scanf("%d%d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);

            parent.push_back(u);
            parent.push_back(v);
        }

        int ans = 0;
        for(auto i: parent){
            if(!visited[i]){
                ans += dfs(i, false);
                for(int i=0; i<2; ++i) bipartite[i].clear();
            }
        }
        printf("Case %d: %d\n", cn, ans);
    }
    return 0;
}