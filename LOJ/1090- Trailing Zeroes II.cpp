#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6+2;

vector<int> vec2, vec5;
int cnt_div(int n, vector<int> &vec){
    int var, ans = 0;
    for(auto it: vec){
        var = n/it;
        if(!var) return ans;
        ans += var;
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int div2 = 2, div5 = 5;
    
    while(div2 < MX){
        vec2.push_back(div2);
        div2 <<= 1;
    }
    while(div5 < MX){
        vec5.push_back(div5);
        div5 *= 5;
    }
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn){
        int n, r, p, q; cin>>n>>r>>p>>q;
        
        int ans2 = cnt_div(n, vec2), n2 = p;
        ans2 -= cnt_div(n-r, vec2); 
        ans2 -= cnt_div(r, vec2);
        int ans2_ = 0;
        while(n2){
            if(n2&1) break;
            ++ans2_; n2 >>= 1;
        }
        ans2 += q*ans2_;

        int ans5 = cnt_div(n, vec5), n5 = p;
        ans5 -= cnt_div(n-r, vec5); 
        ans5 -= cnt_div(r, vec5);
        int ans5_ = 0;
        while(n5%5==0){
            ++ans5_; n5 /= 5; 
        }
        ans5 += q*ans5_;

        cout<<"Case "<<cn<<": "<<min(ans2, ans5)<<'\n';
    }
}
