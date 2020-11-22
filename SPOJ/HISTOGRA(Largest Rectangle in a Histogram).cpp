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
    FIO int n; 
    while(cin>>n and n){
        int height[n+1]; 
        for(int i=0; i<n; ++i) cin>>height[i];
        height[n] = -1;

        int i = 0, area = 0;
        stack<int> stk;
        while(i <= n){
            if(stk.empty() or height[stk.top()] <= height[i])
                stk.push(i++);
            else{
                int top_st = stk.top();
                stk.pop();

                if(stk.empty()) area = max(area, height[top_st]*i);
                else area = max(area, height[top_st]*(i-stk.top()-1));
            }
        }
        cout<<area<<'\n';
    }   
}
