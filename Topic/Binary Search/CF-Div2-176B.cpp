#include "bits/stdc++.h"
using namespace std;
using LL = long long;
 
LL n, k;
LL sum(LL x){
    return x*(x+1)/2;
}
LL find(LL x){
    return sum(k) - sum(k-x) - x + 1;
}
 
int main(){
     cin>>n>>k;
    
    LL ans;
    if(sum(k)- k+1 < n) {
        ans = -1;
    }
    else {
        LL hi = k, lo = 0;
        while(lo <= hi){
            LL mid = (hi+lo)/2;
 
            if(find(mid) >= n)
                ans = mid, hi = mid - 1;
            else   
                lo = mid + 1;
        }
    }    
    cout<<ans<<"\n";
}
