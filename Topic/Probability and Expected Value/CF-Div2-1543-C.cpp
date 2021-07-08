//Topic: EXPECTED VALUE
//Link: https://codeforces.com/contest/1543/problem/C
//Expected value explained clearly in the problem

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
 
const double ths = 1e-12; //I've no idea why 1e-10 or bigger doesn't get AC -_-
double ans, v;
 
void EV(double c, double m, double p, double pro, int cnt){
    if(pro < ths) return;
    
    ans += cnt * p * pro;
    if(c < ths and m < ths) return;
 
    // debug(cnt, pro*p);
    if(c>v and m > ths) EV(c-v, m+(v/2.0), p+(v/2.0), c*pro, cnt + 1);
    else if(c>v and m < ths) EV(c-v, 0, p+v, c*pro, cnt + 1);
    else if(c<v and m < ths) EV(0, 0, p+c, c*pro, cnt + 1);
    else EV(0, m+(c/2.0), p+(c/2.0), c*pro, cnt+1);
 
    if(m>v and c > ths) EV(c+(v/2.0), m-v, p+(v/2.0), m*pro, cnt + 1);
    else if(m>v and c < ths) EV(0, m-v, p+v, m*pro, cnt + 1);
    else if(m<v and c < ths) EV(0, 0, p+m, m*pro, cnt + 1);
    else EV(c+(m/2.0), 0, p+(m/2.0), m*pro, cnt+1);
}
signed main(){
    FIO TC{
        double c, m, p; cin>>c>>m>>p>>v;
 
        ans = 0;
        EV(c, m, p, 1.0, 1);
        cout<<fixed<<setprecision(8)<<ans<<'\n';
    } 
}
