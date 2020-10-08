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
    FIO int n, k; cin>>n>>k;
    int a[n];

    for(int i=0; i<n; ++i){
        int var; cin>>var;

        if(var < 0 and k > 0){
            a[i] = -var, --k;
        }
        else 
            a[i] = var;
    }
    sort(a, a+n);

    int sum = k&1? -a[0]: a[0];
    for(int i=1; i<n; ++i){
        sum += a[i];
    }
    cout<<sum;
}
