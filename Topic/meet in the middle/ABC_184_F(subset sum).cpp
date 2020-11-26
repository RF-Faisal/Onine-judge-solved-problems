#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "E:\CP\Debugger\debugger.h"
// #else 
// #define debug(x...)
// #endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

int les_equal(vector<int> &s, int key){
    int siz = s.size();
    int lo = 0, hi = siz-1, ans = 0;
    
    while(hi >= lo){
        int mid = lo + (hi - lo)/2;
        
        if(s[mid] <= key){
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else 
            hi = mid - 1;
    }
    return ans;
}
signed main(){
    FIO int n, n1, n2, t; cin>>n>>t;

    n1 = (n+1)/2;
    n2 = n/2;
    int a1[n1]; for(int &i: a1) cin>>i;
    int a2[n2]; for(int &i: a2) cin>>i;

    vector<int> set1, set2;
    for(int mask=0; mask<(1<<n1); ++mask){
        int temp_sum = 0;
        for(int i=0; i<n1; ++i){
            int f = 1 << i;
            if(f&mask)
                temp_sum += a1[i];
        }
        set1.push_back(temp_sum);
    }
    for(int mask=0; mask<(1<<n2); ++mask){
        int temp_sum = 0;
        for(int i=0; i<n2; ++i){
            int f = 1 << i;
            if(f&mask)
                temp_sum += a2[i];
        }
        set2.push_back(temp_sum);
    }
    sort(set2.begin(), set2.end());
    
    // for(auto itr: set2) cout<<itr<<' ';
    //     cout<<'\n';
    // for(auto itr: set1) cout<<itr<<' ';
    //     cout<<'\n';
    
    int ans = 0;
    for(auto it: set1){
        int left = t - it;

        if(left < 0) continue;
        int indx = les_equal(set2, left);
        int temp_sum_set2 = (indx != -1? (it + set2[indx]): 0);  
        if(temp_sum_set2 <= t)
            ans = max(ans, temp_sum_set2);
    }
    cout<<ans;
}
