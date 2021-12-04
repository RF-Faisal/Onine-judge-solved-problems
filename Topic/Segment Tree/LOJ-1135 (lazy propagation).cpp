//https://lightoj.com/problem/count-the-multiples-of-3

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
// #define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
#define LFT st, (st+ed)>>1, node<<1
#define RHT ((st+ed)>>1)+1, ed, (node<<1)+1

const int MX = 1e5+2;
int ara[MX], tree[4*MX][3], lazy[4*MX];

void build(int st, int ed, int node){
    if(st==ed){
        tree[node][0] = 1;
        return;
    }

    build(LFT);
    build(RHT);

    for(int i=0; i<3; ++i)
        tree[node][i] = tree[node<<1][i] + tree[(node<<1)+1][i];
}

void circulate(int a[3], int var){
    int temp[3];
    for(int i=0; i<3; ++i)
        temp[i] = a[i];

    for(int i=0; i<3; ++i)
        a[(i+var)%3] = temp[i];
}
int query(int st, int ed, int node, int qs, int qe){
    if(lazy[node]){
        if(st != ed){
            lazy[node<<1] += lazy[node]; 
            lazy[(node<<1)+1] += lazy[node];    
        }
        circulate(tree[node], lazy[node]);
        lazy[node] = 0;    
    }

    if(qe<st or ed<qs) return 0;
    if(qs<=st and ed<=qe) return tree[node][0];

    return query(LFT, qs, qe) + query(RHT, qs, qe);
}
void updateRange(int st, int ed, int node, int qs, int qe, int val){
    if(lazy[node]){
        if(st != ed){
            lazy[node<<1] += lazy[node]; 
            lazy[(node<<1)+1] += lazy[node];    
        }
        circulate(tree[node], lazy[node]);
        lazy[node] = 0;    
    }

    if(qe<st or ed<qs) return;
    if(qs<=st and ed<=qe){
        circulate(tree[node], val);
        if(st != ed){
            lazy[node<<1] += val;
            lazy[(node<<1)+1] += val;
        }
        return;
    }
    
    updateRange(LFT, qs, qe, val);
    updateRange(RHT, qs, qe, val);

    for(int i=0; i<3; ++i){
        tree[node][i] = tree[node<<1][i] + tree[(node<<1)+1][i];
    }
}

signed main(){
    FIO TC{
        int n, q; cin>>n>>q;
        
        memset(ara, 0, sizeof(ara));
        memset(lazy, 0, sizeof(lazy));
        memset(tree, 0, sizeof(tree));
        
        build(0, n-1, 1);

        cout<<"Case "<<cn<<":\n";
        while(q--){
            int t, l, r; cin>>t>>l>>r;

            if(t) cout<<query(0, n-1, 1, l, r)<<'\n';
            else updateRange(0, n-1, 1, l ,r, 1);
        }
    }
}
