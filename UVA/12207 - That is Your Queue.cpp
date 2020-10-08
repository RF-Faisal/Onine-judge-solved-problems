#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

signed main(){
    FIO int p, c, tc = 0;
    while(cin>>p>>c and (p and c)){
        deque<int> q; 

        int mn = min(p, c);
        for(int i=1; i<=mn; ++i)
            q.push_back(i);

        cout<<"Case "<<++tc<<":\n";
        

        while(c--){
            char ch; cin>>ch;
            if(ch == 'N'){
                cout<<q[0]<<'\n';
                q.push_back(*q.begin());
                q.erase(q.begin());
            }
            else{
                int n; cin>>n;
                // cout<<n<<'\n';

                for(auto it = q.begin(); it != q.end(); ++it){
                    if(*it == n){
                        q.erase(it);
                        break;
                    }
                }
                q.push_front(n);
            }
        }
    }   
}
