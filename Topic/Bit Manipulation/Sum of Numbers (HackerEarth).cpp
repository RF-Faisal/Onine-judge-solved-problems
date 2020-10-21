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
    FIO TC{
        int n; cin>>n;
        int a[n]; for(int &i: a) cin>>i;
        int sum; cin>>sum;

        bool flag = false;
        int tot = 1 << n;
        for(int mask = 0; mask < tot; ++mask){
            int temp_sum = 0;
            for(int i=0; i<n; ++i){
                int f = 1<<i;
                if(f&mask)
                    temp_sum += a[i];
            }
            if(temp_sum == sum){
                flag = true; break;
            }
        }
        cout<<(flag? "YES\n": "NO\n");
    }   
}
