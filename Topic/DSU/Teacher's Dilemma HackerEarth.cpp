#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7, MX = 1e5+2;
int par[MX];

int Find(int n){
    if(par[n] == n) return n;
    return par[n] = Find(par[n]);
}
void UNION(int a, int b){
    int x = Find(a), y = Find(b);
    
    if(x != y) par[x] = y;
}
signed main(){
    int n, m; cin>>n>>m;

    for(int i=1; i<=n; ++i) par[i] = i;
    for(int i=1; i<=m; ++i){
        int a, b; cin>>a>>b;

        UNION(a, b); 
    }
    map<int, int> mp;
    for(int i=1; i<=n; ++i) ++mp[Find(i)];
    int ans = 1;
    for(auto it: mp) ans = (ans*it.second) % MOD;

    cout<<ans;
}
