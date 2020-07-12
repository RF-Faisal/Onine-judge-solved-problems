#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const LL MX = 1e4+5;

LL H[MX], C[MX], n;
LL cost(LL h){
    LL sum = 0;
    for(LL i=0; i<n; i++){
        sum += C[i]*abs(H[i] - h);
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(LL i=0; i<n; i++) cin>>H[i];
        for(LL i=0; i<n; i++) cin>>C[i];
        
        LL hi = 10000, lo = 0;
        while(lo <= hi){
            LL mid1 = lo + (hi-lo)/3;
            LL mid2 = hi - (hi-lo)/3;

            if(cost(mid1) > cost(mid2))
                lo = mid1 + 1;
            else 
                hi = mid2 - 1;            
        }
        cout<<cost(lo)<<"\n";
    }
    return 0;
}