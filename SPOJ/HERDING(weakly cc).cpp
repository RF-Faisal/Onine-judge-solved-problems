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
const int MX = 1002;

int n, m, cc = 0;
string s[MX];
int vis[MX][MX];

void bfs(int a, int b, int path_no){
    // vis[a][b] = true;
    queue<pair<int, int>> q;
    q.push({a, b});

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first, y = cur.second;
        if(vis[x][y]){
            if(vis[x][y] == path_no) ++cc;
            break;
        }
        vis[x][y] = path_no;

        if(x>0 and s[x][y] == 'N') q.push({x-1, y});
        else if(x<n-1 and s[x][y] == 'S') q.push({x+1, y});
        else if(y>0 and s[x][y] == 'W') q.push({x, y-1});
        else if(y<m-1 and s[x][y] == 'E') q.push({x, y+1});
    }
}

signed main(){
    FIO cin>>n>>m;
    
    for(int i=0; i<n; ++i) cin>>s[i];

    int path_no = 1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!vis[i][j]) 
                bfs(i, j, path_no), ++path_no;
        }
    }   
    cout<<cc;
}
