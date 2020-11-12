/*
we iterate from left to right.
1. If we find current step is higher than previous one then ++res
2. If we find current step is lower than previous one then
    - if this is the first time time this step comes, then ++res
    - else this step has appeared before
         - if between the previous one and the current one there is no step lowwer than them then do nothing(continue)
         - else ++res
*/
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
    FIO int n, res = 0; cin>>n;
    
    stack<int> stk;
    for(int i=0; i<n; ++i){
        int height, width; cin>>width>>height;

        if(stk.empty()){
            ++res, stk.push(height);
        }
        else{
            while(!stk.empty() and stk.top() > height)
                stk.pop();
            
            if(stk.empty())
                ++res, stk.push(height);
            else if(stk.top() == height) 
                continue;
            else
                ++res, stk.push(height);
        }
    }
    cout<<res;   
}
