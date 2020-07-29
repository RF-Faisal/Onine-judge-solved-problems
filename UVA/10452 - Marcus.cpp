#include "bits/stdc++.h"
using namespace std;

int m, n;
char grid[10][10], src[] = "IEHOVA#";
string path[] = {"forth", "left", "right"};

void dfs(int i, int j, int c){
    if(c>0 and c<7) cout<<" ";

    if(grid[i][j]=='#'){
        cout<<"\n";
        return;
    }
    
    if(grid[i-1][j] == src[c]){
        cout<<path[0];
        return dfs(i-1, j, c+1);
    }
    if(grid[i][j+1] == src[c]){
        cout<<path[2];
        return dfs(i, j+1, c+1);
    }
    if(grid[i][j-1] == src[c]){
        cout<<path[1];
        return dfs(i, j-1, c+1);
    }
}

int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int TC; cin>>TC;
    while(TC--){
        cin>>m>>n;
        int x, y;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j){
                cin>>grid[i][j];
                if(grid[i][j] == '@') x = j, y = i;
            }
        dfs(y, x, 0);
    }
}