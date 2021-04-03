#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn)

signed main(){    
        FIO TC{
        string s; cin>>s;

        int l = 0, m1 = 0, lazy = 0, k = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '^') {
                if(lazy) ++m1, --lazy;
                ++l;
            }
            else if(l>m1+lazy) ++lazy;
        }
        cout<<"Case "<<cn<<": "<<min(m1, l/2)<<'\n';
    }
}
