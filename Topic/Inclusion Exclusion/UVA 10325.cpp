#include<bits/stdc++.h>
using namespace std;
#define int long long 

inline int LCM(int a, int b){
    return a*b/__gcd(a, b);
}
int PIE(int div[], int n, int num){
    int sum = 0;
    for(int msk=1; msk < (1<<n); ++msk){
        int bit_cnt = 0;
        int cur_lcm = 1;
        
        for(int i=0; i<n; ++i){
            if(msk & (1<<i)){
                ++bit_cnt;
                cur_lcm = LCM(cur_lcm, div[i]);
            }
        }
        int cur = num/cur_lcm; 
        if(bit_cnt&1) sum += cur;
        else sum -= cur;
    }
    return num - sum;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n, m; 
    while(cin>>n>>m)
    {
        int a[m]; for(int &i: a) cin>>i;
        
        cout<<PIE(a, m, n)<<'\n';
    }
}
