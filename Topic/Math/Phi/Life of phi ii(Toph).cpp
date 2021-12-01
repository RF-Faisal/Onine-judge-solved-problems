//problem link: https://toph.co/p/life-of-phi-ii

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

int phi(int n){ //O(sqrt(n))
    int res = n;

    for(int p=2; p*p<=n; ++p){
        if(n%p== 0){
            while(n%p == 0)
                n /= p;
            res -= res/p;
        }
    }
    if(n>1) res -= res/n;
    return res;
}

signed main(){
    FIO int n, m; cin>>n>>m;
    int res3 = phi(n*m);
    int res1 = m*phi(n) - res3;
    int res2 = n*phi(m) - res3;

    cout<<res1<<' '<<res2<<' '<<res3<<'\n';
}
