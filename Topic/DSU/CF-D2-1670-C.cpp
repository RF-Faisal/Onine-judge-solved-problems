#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7, MX = 5e5+2;
int par[MX], sz[MX];

int Find(int n){
    if(par[n] == n) return n;
    return par[n] = Find(par[n]);
}
void UNION(int a, int b){
    int x = Find(a), y = Find(b);
    
    if(x == y) return;
    if(sz[y] < sz[x]) swap(x,y);
     
    sz[y] += sz[x];
    par[x] = y;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        map<int, bool> used;
        int a[n]; for(int &i: a) cin>>i;
        int b[n]; for(int &i: b) cin>>i;
        int d[n]; for(int &i: d) cin>>i, used[i]=true;
        for(int i=1; i<=n; ++i) par[i] = i;

        int ans = 1;
        for(int i=0; i<n; ++i){
            int u=a[i], v=b[i];

            UNION(u, v);
        }

        set<int> cnt;
        for(int i=1; i<=n; ++i){
            int P = Find(i);

            if(Find(i) != i) cnt.insert(Find(i));
        }
        for(auto [x, y]: used){
            int P = Find(x);
            if(cnt.find(P) != cnt.end()){
                cnt.erase(P);
            }
        }

        for(int i=0; i<cnt.size(); ++i)
            ans = (ans<<1) % MOD;
        cout<<ans<<'\n';
    }
}
