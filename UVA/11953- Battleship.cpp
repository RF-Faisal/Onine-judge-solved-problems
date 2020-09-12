#include<bits/stdc++.h>
using namespace std;

int n;
char grid[101][101];
bool vis[101][101];
bool still_alive;

void dfs(int y, int x){
    if(x<0 or x>=n or y<0 or y>=n) return;
    if(vis[y][x] or grid[y][x]=='.') return;

    vis[y][x] = true;
    if(grid[y][x]=='x') still_alive = true;

    dfs(y, x+1);
    dfs(y, x-1);
    dfs(y+1, x);
    dfs(y-1, x);
}

int main(){
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn)
    {
        cin>>n;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin>>grid[i][j];

        memset(vis, false, sizeof vis);

        int cnt = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(!vis[i][j] and grid[i][j]!= '.'){
                    dfs(i, j);
                    cnt += still_alive;
                    still_alive = false;
                }

        cout<<"Case "<<cn<<": "<<cnt<<"\n";
    }
}