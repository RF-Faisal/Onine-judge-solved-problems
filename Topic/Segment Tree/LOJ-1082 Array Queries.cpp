#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5+10;
int tree_min[4*MX+10], A[MX];

void init(int node, int st, int ed){
    if(st == ed){
        tree_min[node] = A[st];
        return;
    }

    int left = 2*node, right = 2*node + 1;
    int mid = (st + ed)/2;

    init(left, st, mid);
    init(right, mid+1, ed);

    tree_min[node] = min(tree_min[left], tree_min[right]);
}

int query(int node, int st, int ed, int range_l, int range_r){
    int ret = MX;

    if(range_l <= st and ed <= range_r)
        return tree_min[node];
    //if(range_l > ed or range_r < st) 
       // return MX;
    int left = 2*node, right = 2*node + 1; 
    int mid = (st + ed)/2; 
    
    if(range_l <= mid)
        ret = min(ret, query(left, st, mid, range_l, range_r));
    if(range_r >= mid +1)
        ret = min(ret, query(right, mid+1, ed, range_l, range_r));
    return ret;
}


signed main(){
    int tc; scanf("%d", &tc);
    for(int cn=1; cn<=tc; ++cn)
    {
        int n, q; scanf("%d%d", &n, &q);
        for(int i=1; i<=n; ++i) scanf("%d", &A[i]);

        init(1, 1, n);
        printf("Case %d:\n", cn);
        while(q--){
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }   
}
