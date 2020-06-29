/*problem id: Atcoder 172-C-Tsondoku 
link = https://atcoder.jp/contests/abc172/tasks/abc172_c

Author : Faosal
idea : 
    1. take prefix sum of the books of two tables,
    2. then take one table and binary search in the other table

complexity : nlog(n)
*/ 

#include "bits/stdc++.h"
using namespace std;
typedef long long LL;

signed main(){
    LL n, m, k; cin>>n>>m>>k;
    LL Ai, pref_a[n+1] = {}, Bi, pref_b[m+1] = {};

    for(int i=0; i<n; i++){
        cin>>Ai;
        pref_a[i+1] = pref_a[i] + Ai;
    }
    for(int i=0; i<m; i++){
        cin>>Bi;
        pref_b[i+1] = pref_b[i] + Bi;
    }

    LL ans = 0;
    for(LL i=0; i<=n; i++){
        LL r = m, l = 0, target = k - pref_a[i];
        while(l <= r){
            LL mid = (r+l)/2;

            if(pref_b[mid] <= target)
                ans = max(ans, i+mid), l = mid + 1;
            else
                r = mid - 1;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
