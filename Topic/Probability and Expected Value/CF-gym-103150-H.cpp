//https://codeforces.com/gym/103150/problem/H

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

signed main(){
    FIO TC{
        int n; cin>>n;
        long double res = 0;

        for(int i=0; i<n; ++i){
            int hight; cin>>hight;

            if(!hight) continue;
            else if(hight < 100) res += 2.0 - 1/pow(2, hight-1);
            else res += 2;
        }

        cout<<fixed<<setprecision(9)<<res<<'\n';
    }
}
