#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18+2;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    int a[n]; for(int &i: a) cin>>i;

    int box_sz = sqrt(n);
    int len = (n+box_sz-1)/box_sz;
    int sqrt_box[len];
    for(int &i: sqrt_box) i = INF;
     
    for(int i=0; i<len; ++i)
    {
        int st_indx = i*box_sz;
        for(int j=0; j<box_sz; ++j)
        {
            if(st_indx + j == n) break;
            sqrt_box[i] = min(a[st_indx+j], sqrt_box[i]);
        }
    }

    int q, x, y; cin>>q;
    while(q--)
    {
        cin>>x>>y;
        
        int ans = INF;
        int left_box = (x+box_sz-1)/box_sz, right_box = y/box_sz;
        // cout<<"lb "<<left_box<<'\n'<<"rb"<<right_box<<'\n';

        if(left_box >= right_box){
            for(int i=x; i<=y; ++i) ans = min(ans, a[i]);
            cout<<ans<<'\n';
            continue;
        }
        for(int i=x; i<left_box*box_sz; ++i) ans = min(ans, a[i]);
        for(int i=y; i>=right_box*box_sz; --i) ans = min(ans, a[i]);
        for(int i=left_box; i<right_box; ++i) ans = min(ans, sqrt_box[i]); //be careful where to use < or <=
        
        cout<<ans<<'\n'; 
    }
}
