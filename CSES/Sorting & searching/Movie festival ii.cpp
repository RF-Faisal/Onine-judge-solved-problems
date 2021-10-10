#include<bits/stdc++.h>
using namespace std;
#define int long long 

typedef struct TIME{
    int start, finish;

    bool operator < (TIME &rt){
        return finish < rt.finish;
    }
};

signed main(){
    int n, k; cin>>n>>k;
    
    TIME ara[n];
    for(int i=0; i<n; ++i)
        cin>>ara[i].start>>ara[i].finish;

    sort(ara, ara+n);
    
    multiset<int> end_time;
    for(int i=0; i<k; ++i)
        end_time.insert(0);
    
    int cnt = 0;
    for(int i=0; i<n; ++i){
        auto it = end_time.upper_bound(ara[i].start);
        if(it == end_time.begin()) continue;

        end_time.erase(--it);
        end_time.insert(ara[i].finish);
        ++cnt;
    }

    cout<<cnt<<'\n';
}
