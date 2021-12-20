#include<bits/stdc++.h>
using namespace std;

#define LFT st, (st+ed)>>1, node<<1
#define RHT ((st+ed)>>1) + 1, ed, (node<<1)+1

const int MX = 1e5+2;
int tree[4*MX+2], lazy[4*MX];
string str;

void build_tree(int st, int ed, int node){
    if(st==ed){
        tree[node] = str[st]-'0';
        return;
    }
    build_tree(LFT);
    build_tree(RHT);
    
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}
int query(int st, int ed, int node, int qs, int qe){
    if(lazy[node]){
        if(st != ed){
            lazy[node<<1] += lazy[node]; 
            lazy[(node<<1)+1] += lazy[node];    
        }
        tree[node] += lazy[node];
        lazy[node] = 0;    
    }
    
    if(qe<st or ed<qs) return 0;
    if(qs<=st and ed<=qe) return tree[node];
    
    return query(LFT, qs, qe) + query(RHT, qs, qe);
}

void updateRange(int st, int ed, int node, int qs, int qe, int val){
    if(lazy[node]){
        if(st != ed){
            lazy[node<<1] += lazy[node]; 
            lazy[(node<<1)+1] += lazy[node];    
        }
        tree[node] += lazy[node];
        lazy[node] = 0;    
    }

    if(qe<st or ed<qs) return;
    if(qs<=st and ed<=qe){
        ++tree[node];
        if(st != ed){
            lazy[node<<1] += val;
            lazy[(node<<1)+1] += val;
        }
        return;
    }
    
    updateRange(LFT, qs, qe, val);
    updateRange(RHT, qs, qe, val);

    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}


int main()
{
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn){
        cin>>str;
        
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        
        int n = str.size();
        build_tree(0, n-1, 1);
        int q; cin>>q;
        cout<<"Case "<<cn<<":\n";
        while(q--){
            char ch; cin>>ch;
            if(ch=='I'){
                int L, R; cin>>L>>R;
                updateRange(0, n-1, 1, L-1, R-1, 1);
            }
            else{
                int id; cin>>id; 
                cout<<query(0, n-1, 1, id-1, id-1)%2<<'\n';
            }
        }
    }
}
