#include <bits/stdc++.h>
using namespace std;
 
double find_p(int l, int r, int p){
    int down = r - l + 1;
    int divisible = (r/p) - (l-1)/p;
    int non_divisible = down - divisible;
 
    return (double)non_divisible/down;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p; cin>>n>>p;
    
    int l[n+1], r[n+1];
    for(int i=0; i<n; ++i) cin>>l[i]>>r[i];
    l[n] = l[0], r[n] = r[0];
 
    double exp_val = 0, doller = 1000;
    double p1 = find_p(l[0], r[0], p);
    
    for(int i=1; i<=n; ++i){
        double p2 = find_p(l[i], r[i], p);
        double probability = p1*p2;
        
        exp_val += (1 - probability) * doller * 2;
        p1 = p2;
    }
    cout<<fixed<<setprecision(8)<<exp_val<<'\n';
}
