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

bool tst(int stall[], int dis, int n, int c){ //called an array by reference
    int cnt = 1, i, j = 0;
    
    for(i=0; i<n-1 and cnt < c; ){
        if(stall[i+1] - stall[j] >= dis)
            ++i, ++cnt, j = i;
        else ++i;
    }
    if(cnt < c) return false;
    return true;
}
signed main(){
    FIO TC{
        int n, c; cin>>n>>c;
        int stalls[n]; for(int i=0; i<n; ++i) cin>>stalls[i];
        
        sort(stalls, stalls+n);

        int lo = 0, hi = stalls[n-1], ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            // debug(mid, hi, lo); 
            if(tst(stalls, mid, n, c)){
                ans = max(ans, mid);
                // debug(ans);
                lo = mid + 1;
            }
            else 
                hi = mid - 1;
        }
        cout<<ans<<'\n';
    }   
}
