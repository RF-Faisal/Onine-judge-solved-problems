    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define xx first
    #define yy second
    #define MX (int)1e9
     
    int n, m, k; 
    pair<int, int> rana[21];
     
    inline bool is_set(int mask, int n){
        return (mask & (1<<n));
    }
    int solve(int mask){
        int ltx = MX, lty = MX, rbx = 0, rby = 0;
        for(int i=0; i<k; ++i){
            if(is_set(mask, i)){
                ltx = min(ltx, rana[i].xx), lty = min(lty, rana[i].yy);
                rbx = max(rbx, rana[i].xx), rby = max(rby, rana[i].yy);
            }
        }
     
        int res = ltx * lty;
        res *= (n-rbx+1) * (m-rby+1);
     
        return res; 
    }
    signed main(){
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        int tc; cin>>tc;
     
        for(int cn=1; cn<=tc; ++cn)
        {
            cin>>n>>m>>k;
            for(int i=0; i<k; ++i){
                cin>>rana[i].xx>>rana[i].yy;
            }
     
            int limit = (1<<k) - 1;
            int ans = (n*(n+1)/2) * (m*(m+1)/2);
     
            for(int i=1; i<=limit; ++i)
            {
                if(__builtin_popcountll(i)&1) ans -= solve(i);
                else ans += solve(i);
            }
     
            cout<<ans<<'\n';
        }
    }
