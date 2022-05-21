//https://codeforces.com/gym/103388/problem/N 

#include<bits/stdc++.h>
using namespace std;
#define LFT st, (st+ed)>>1, node<<1
#define RHT ((st+ed)>>1)+1, ed, (node<<1)+1

const int MX = 3e5+5;
int a[MX], n, m;
vector<int> tree[4*MX];

void build(int st, int ed, int node){
    if(st==ed){
        tree[node] = vector<int>(1, a[st]);
        return;
    }

    build(LFT);
    build(RHT);
    
    merge(tree[node<<1].begin(), tree[node<<1].end(), tree[(node<<1)+1].begin(), tree[(node<<1)+1].end(), back_inserter(tree[node]));
}
int Query( int qs, int qe, int val, int st=1, int ed=n, int node=1){
    if(qe<st or ed<qs) return 0;
    if(qs<=st and ed<=qe)
        return tree[node].end() - lower_bound(tree[node].begin(), tree[node].end(), val);
    return Query(qs, qe, val, LFT) + Query(qs, qe, val, RHT);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; ++i) cin>>a[i];

    build(1, n, 1);
    for(int i=0; i<m; ++i){
        int l, r, p; cin>>l>>p>>r;

        if(a[l] >= p) cout<<"0\n";
        else cout<<Query(l+1, l+r, p)<<'\n';
    }
}
