#include<bits/stdc++.h>
using namespace std;
#define int long long 

int LCM(int a, int b){
    return (a*b)/__gcd(a, b);
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;

    for(int cn=1; cn<=tc; ++cn){
        int n, m, a, dd; cin>>n>>m>>a>>dd;
        --n;
        
        vector<int> d(5); d[0] = a;
        for(int i=1; i<5; ++i) d[i] = dd + d[i-1];

        int res = 0;
        for(int msk=0; msk<(1<<5); ++msk){
            int div = 1;
            int bit_cnt = 0;
            for(int i=0; i<5; ++i){
                if(msk & (1 << i)){
                    ++bit_cnt;
                    div = LCM(div, d[i]);    
                }
            }
            if(bit_cnt&1) res -= (m/div - n/div);
            else res += (m/div - n/div);
        }
        cout<<res<<'\n';
    }
}
