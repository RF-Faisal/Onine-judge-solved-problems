#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
#define LFT st, (st+ed)>>1, node<<1 
#define RHT ((st+ed)>>1)+1, ed, (node<<1)+1

const int MX = 1e5+2;
int a[MX], tree[4*MX];

void build(int st, int ed, int node){
    if(st==ed){
        tree[node] = a[st];
        return;
    }
    build(LFT);
    build(RHT);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

int query(int st, int ed, int node, int qs, int qe){
    if(qe<st or  ed<qs) return 0;
    if(qs<=st and ed<=qe) return tree[node];
    return query(LFT, qs, qe) + query(RHT, qs, qe);
}

void update(int st, int ed, int node, int idx, int val){
    if(idx<st or ed<idx) return;
    if(st==ed and st==idx) {
        tree[node] = val;
        return;
    }
    update(LFT, idx, val);
    update(RHT, idx, val);
    tree[node] = tree[node<<1] + tree[(node<<1) + 1];
}

signed main(){
    FIO TC{
        int n, q; cin>>n>>q;
        for(int i=0; i<n; ++i) cin>>a[i];

        build(0, n-1, 1);
        cout<<"Case "<<cn<<":\n";
        while(q--){
            int ty, i, j;
            cin>>ty;

            if(ty==1){
                cin>>i;
                cout<<query(0, n-1, 1, i, i)<<'\n';
                a[i] = 0;
                update(0, n-1, 1, i, a[i]);
            }
            else if(ty==2){
                cin>>i>>j; 
                a[i] += j;
                update(0, n-1, 1, i, a[i]);
            }
            else{
                cin>>i>>j;
                cout<<query(0, n-1, 1, i, j)<<'\n';
            }
        }
    }
}
