#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int MOD = 1e9+7;
int sum(int n){
    if(n&1) return ((n+1)>>1)*n % MOD;
    return (n>>1)*(n+1) % MOD;
}
void solve(){
    int n; cin>>n;

    deque<pair<int, int>> div_st, div_ed;
    for(int i=1; i*i<=n; ++i){
        div_st.emplace_back(i, n/i);

        if(i != n/i)
            div_ed.emplace_front(n/i, i);
    }
    for(auto it: div_ed)
        div_st.emplace_back(it);

    // debug(div_st);
    int st = 1, ans = 0;
    for(auto it: div_st){
        int ed = it.first % MOD;
        int cnt = it.second % MOD;

        int tmp = sum(ed) - sum(st-1);
        tmp = (tmp + MOD) % MOD;
        tmp = (tmp * cnt) % MOD;
        ans = (ans + tmp) % MOD;
//         ans = (ans + (cnt*((sum(ed) - sum(st-1) + MOD) % MOD) % MOD)) % MOD;
        st = ed + 1;
    }

    cout<<ans;
}
signed main(){
    FIO solve();
}
