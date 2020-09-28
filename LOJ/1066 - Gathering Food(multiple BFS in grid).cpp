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
#define ff first
#define ss second

const int mx = 11;
char grid[mx][mx], mx_let;
int n, x_, y_;

int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, -1, 1};

int bfs(int b, int a, char food_at) //b-> y, a-> x
{
    bool vis[11][11] = {};
    queue<pair<pair<int, int>, int>> qu;
    qu.push({{b, a}, 0});

    while(!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        // vis[cur.ff.ff][cur.ff.ss] = true;

        for(int i=0; i<4; ++i)
        {   
            int y = cur.ff.ff + fy[i], x = cur.ff.ss + fx[i];
        
            if(y < 0 or y >= n) continue;
            if(x < 0 or x >= n) continue;
            if(vis[y][x]) continue;

            if(grid[y][x] == food_at){
                grid[y][x] = '.';
                y_ = y, x_ = x;
                return cur.ss + 1;
            }
            if(grid[y][x] == '.'){
                qu.push({{y, x}, cur.ss + 1});
                vis[y][x] = true;
            }
        }
    }
    return -1;
}

signed main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    FIO TC{
        cin>>n;
        mx_let = 'A';

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin>>grid[i][j];
                
                if(grid[i][j] != '#' or grid[i][j] != '.'){
                    if(grid[i][j] > mx_let)
                        mx_let = grid[i][j];
                    if(grid[i][j] == 'A')
                        grid[i][j] = '.',y_ = i, x_ = j;
                }
            }
        }
        bool ok = true;
        int ans = 0;// bfs(y_, x_, 'A');
        for(char i='B'; i<= mx_let; ++i)
        {
            int var = bfs(y_, x_, i);
            if(var == -1){
                ok = false;
                break;
            }
            ans += var;
        }
        cout<<"Case "<<cn<<": ";
        if(ok) cout<<ans<<"\n";
        else cout<<"Impossible\n";
    }   
}
