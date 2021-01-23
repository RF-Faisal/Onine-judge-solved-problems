//problem link: https://atcoder.jp/contests/abc189/tasks/abc189_c

#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n; cin>>n;
    int org[n]; for(int &i: org) cin>>i;

    stack<int> stk; 
    int i = 0, area = -1, tp = 0;
    while(i < n){
        if(stk.empty() or org[stk.top()] <= org[i]){
            stk.push(i++);
        }
        else{
            tp = stk.top(); stk.pop();
            area = max(area, org[tp] * (stk.empty()? i: (i - stk.top() - 1)));
            // cout<<area<<' ';
        }
    }
    while(!stk.empty()){
        tp = stk.top(); stk.pop();
        area = max(area, org[tp] * (stk.empty()? i: (i-stk.top()-1)));
    }

    cout<<area<<'\n';
}
