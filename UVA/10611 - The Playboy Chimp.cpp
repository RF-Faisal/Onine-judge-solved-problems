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

signed main(){
    FIO int n, q; cin>>n;
    int a[n]; for(int &i: a) cin>>i;

    cin>>q; int quer[q]; for(int &i: quer) cin>>i;

    for(int i=0; i<q; ++i)
    {   
        int hi = quer[i];
        int x = lower_bound(a, a+n, hi) - a - 1;
        int y = upper_bound(a, a+n, hi) - a;

        // debug(x, y);

        if(x < 0) cout<<"X ";
        else cout<<a[x]<<' ';
        if(y == n) cout<<"X\n";
        else cout<<a[y]<<"\n";
    }
    return 0;
}
