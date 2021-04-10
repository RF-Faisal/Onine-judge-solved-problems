#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "/home/faisal/Documents/debugger.h"
// #else 
// #define debug(x...)
// #endif
#define int long long

class Trio{
    public:
        int nth, want, sad, id;
};
class comp{
    public:
        bool operator()(const Trio &x, Trio &y){
            if(x.nth == y.nth) 
                return x.sad > y.sad;
            return x.nth < y.nth;
        }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc; 
    for(int cn=1; cn<=tc; ++cn)
    {   
        int n, d; cin>>n>>d;
        Trio ipc[n]; 
        int tot_sad = 0, freq_want[n+1] = {};

        for(int i=0; i<n; ++i){
            cin>>ipc[i].nth>>ipc[i].want>>ipc[i].sad;
            freq_want[i] = ipc[i].want; ipc[i].id = i;

            tot_sad += ipc[i].sad * ipc[i].want;
        }
        
        sort(ipc, ipc+n, comp());

        priority_queue<pair<int, int>> pq;
        int it = 0;
        for(int i=1; i<=d; ++i){
            while(ipc[it].nth == i){
                pq.push({ipc[it].sad, ipc[it].id});
                ++it;
            }
            if(pq.empty()) continue;
            // debug(pq.top(), i);
            tot_sad -= pq.top().first;
            freq_want[pq.top().second]--;
            if(!freq_want[pq.top().second]) pq.pop();
        }   

        cout<<tot_sad<<'\n';
    }
}
