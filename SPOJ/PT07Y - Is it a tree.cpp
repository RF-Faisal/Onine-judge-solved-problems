#include<iostream>
#include<vector>
using namespace std;

int vis[10001];
vector<int> ad_list[10001];

void dfs(int node){
    vis[node] = 1;

    for(int i: ad_list[node])
        if(vis[i] == 0)
            dfs(i);
}
int main(){
    int m, n, a, b, min_node = 20005; cin>>n>>m;
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        ad_list[a].push_back(b);
        ad_list[b].push_back(a);

        if(min_node>a) min_node = a;
        if(min_node>b) min_node = b;
    }
    if(n-1 != m){
        cout<<"NO\n";
        return 0;
    }
    dfs(min_node);
    
    bool ok = true;
    for(int i=min_node; i<=m; i++){
        if(vis[i]==0){
            ok = false; 
            break;
        }
    }
    cout<<(ok? "YES\n": "NO\n");
    return 0;
}
