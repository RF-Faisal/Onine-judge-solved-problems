//problem link: https://www.hackerrank.com/contests/codewar2020-adv-wk-8/challenges/our-phoenix/problem
//setter Wasif Vai

#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "D:\CP\Debugger\debugger.h"
// #else 
// #define debug(x...)
// #endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
#define CN cout<<"Case "<<cn<<": "

signed main(){
    int n, m; cin>>n>>m;
    int q; cin>>q;
    deque<pair<int, int>> dq;
    bool mp_f[n+1][m+1];

    int cnt = 0;
    for(int i=1; i<=n; ++i){
        if(i&1){
            for(int j=1; j<=m; ++j){
                dq.push_back({i, j});
                mp_f[i][j] = false;
            }
        }
        else{
            for(int j=m; j>=1; --j){
                dq.push_back({i, j});
                mp_f[i][j] = false;
            }
        }
    }   

    string str; int x, y; pair<int, int>  var;
    map<pair<int, int>, int> mp;
    // map<pair<int, int>, bool> mp_f;
    while(q--){
        cin>>str; 
        if(str == "scan"){
            hell:
            var = dq.front();
            dq.pop_front();
            
            if(!mp_f[var.first][var.second]) goto baal;
            
            if(cnt+1-mp[var] < m*n) 
                goto hell;
            
            baal:
            mp[var] = ++cnt;
            mp_f[var.first][var.second] = true;
            dq.push_back(var);
            
            cout<<var.first<<' '<<var.second<<'\n';
        }
        else{
            cin>>x>>y; var = {x, y};
            
            dq.push_front(var);
            mp_f[x][y] = false; 
        }
    }
}
