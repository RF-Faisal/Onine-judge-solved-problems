/*
When the game ends there will be only piles with height 1
be left. So a pile with height h will be responsible for 
(h-3)/2 + 1 moves.
Daenerys wins if there are odd number of moves
else Stannis stans.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

signed main(){
    FIO int n; cin>>n;
    int step = 0;
    for(int i=0; i<n; ++i){
        int var; cin>>var;
        if(var>1)
            step += (var-3)/2 + 1;
    }

    cout<<(step&1? "Daenerys": "Stannis");
}
