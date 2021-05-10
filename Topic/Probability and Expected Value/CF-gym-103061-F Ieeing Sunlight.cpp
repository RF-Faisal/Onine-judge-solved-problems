//Probability and Expected value

#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5+5;
#define l first
#define r second
#define err 1e-9

int n, m;
pair<double, double> a[MX];

double func(double x){
    double cnt = 0.0;
    
    for(int i=0; i<n; ++i)
    {
        if(a[i].r <= x) cnt += 1.0;
        else if(a[i].l > x) continue;
        else cnt += (x - a[i].l)/(a[i].r - a[i].l);
    }
    // cout<<fixed<<setprecision(20)<<cnt<<'\n';
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;

    for(int i=0; i<n; ++i)
        cin>>a[i].l>>a[i].r;
    
    double hi = 2e9, lo = 0, mid, ans;
    for(int i=0; i<60; ++i)
    {
        mid = (hi + lo)/2;
        double temp = func(mid);

        if(temp >= m)
            hi = mid;
        else 
            lo = mid;
    }

    cout<<fixed<<setprecision(7)<<hi<<'\n';
}
