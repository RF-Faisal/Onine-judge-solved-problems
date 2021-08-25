#include<bits/stdc++.h>
using namespace std;

const int MX = 1e5+2;
int block_size;

int l, r, uniq_val, a[MX], freq[MX];

class Trio{
public:
    int L, R, ID;

    bool operator <(const Trio &obj){
        int a1 = L/block_size;
        int a2 = obj.L/block_size;

        if(a1 == a2) return R < obj.R;
        return a1 < a2;
    }
};

void add(int idx){
    ++freq[a[idx]];
    if(freq[a[idx]] == 1) ++uniq_val;
}
void rmv(int idx){
    --freq[a[idx]];
    if(freq[a[idx]] == 0) --uniq_val;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn)
    {
        int n, q; cin>>n>>q; 
        block_size = sqrt(n);
        
        for(int i=0; i<n; ++i) cin>>a[i];

        Trio Query[q];
        for(int i=0; i<q; ++i){
            cin>>Query[i].L>>Query[i].R;
            
            --Query[i].L, --Query[i].R;
            Query[i].ID = i;
        }
        sort(Query, Query+q);

        uniq_val = 0, l = 0, r = -1;
        int ans[q];
        for(int i=0; i<q; ++i)
        {
            while(Query[i].L > l) rmv(l++);
            while(Query[i].L < l) add(--l);
            while(Query[i].R > r) add(++r);
            while(Query[i].R < r) rmv(r--);

            ans[Query[i].ID] = uniq_val;
        }

        cout<<"Case "<<cn<<":\n";
        for(int i=0; i<q; ++i) cout<<ans[i]<<'\n';

        memset(freq, 0, sizeof(freq));
    }
}
