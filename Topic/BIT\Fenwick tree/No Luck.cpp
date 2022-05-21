//https://codeforces.com/gym/103388/problem/N
// Copied from Swad's code

#include<bits/stdc++.h>
using namespace std; 

const int N = 3e5+5;
int BIT[N], a[N], n, y;

void Update(int x, int delta){
    for(; x<N; x += x&-x)
        BIT[x] += delta;
}
void Range_upd(int l, int r, int delta){
    Update(l ,delta);
    Update(r+1, -delta);
}
int Query(int x){
    int sum = 0;
    for(; x>0; x -= x&-x)
        sum += BIT[x];
    return sum;
}

vector<tuple<int, int, int>> Queries[N];
vector<int> vec[N];

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>y>>n;

    for(int i=1; i<=y; ++i){
        cin>>a[i];
        vec[a[i]].push_back(i);
    }
    for(int i=0; i<n; ++i){
        int l, r, p; cin>>l>>p>>r;
        Queries[p].emplace_back(l, r+l, i);
    }
    
    int ans[n+1];
    for(int p=N-1; p>=0; --p){
        for(int i: vec[p])
            Update(i, 1);
        
        for(auto [l, r, i]: Queries[p])
            ans[i] = (p <= a[l]? 0: Query(r)-Query(l));
    }

    for(int i=0; i<n; ++i)
        cout<<ans[i]<<'\n';
}
 
