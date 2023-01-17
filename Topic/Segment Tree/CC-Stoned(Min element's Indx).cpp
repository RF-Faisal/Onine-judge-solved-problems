//https://www.codechef.com/problems/STONED
//find index of the maximum value 

#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

#define LFT st, (st+ed)>>1, node<<1
#define RHT ((st+ed)>>1) + 1, ed, (node<<1)+1

const int MX = 1e5+5;
int tree[4*MX+2], a[MX];

void build_tree(int st, int ed, int node){
    if(st==ed){
        tree[node] = st;
        return;
    }
    build_tree(LFT);
    build_tree(RHT);
    
    int l_id = tree[node<<1], r_id = tree[(node<<1)+1];
    if(a[l_id] > a[r_id]) tree[node] = l_id;
    else tree[node] = r_id;
}
int query(int st, int ed, int node, int qs, int qe){
    if(qe<st or ed<qs) return -1;
    if(qs<=st and ed<=qe) return tree[node];
    
    int l_id = query(LFT, qs, qe), r_id = query(RHT, qs, qe);
    
    int ans;
    if(l_id == -1) ans = r_id;
    else if(r_id == -1) ans = l_id;
    else if(a[l_id] > a[r_id]) ans = l_id;
    else ans = r_id;
    
    return ans;
}

void solve(){
    int n, q; cin>>n>>q;
    vector<int> res(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    
    stack<int> stk;
    for(int i=n-1; i>=0; --i){
        while(!stk.empty() and a[stk.top()] <= a[i])
            stk.pop();

        if(!stk.empty()) 
            res[i] = 1+res[stk.top()];
        stk.push(i);
    }

    build_tree(0, n-1, 1);

    int l, r;
    while(q--){
        cin>>l>>r;
        --l, --r;
        if(l>r) swap(l, r);
        
        cout<<res[query(0, n-1, 1, l, r)]<<'\n';
    }
}
signed main(){
    FIO TC solve();
}
