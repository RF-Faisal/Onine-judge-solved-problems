/*
Author : RF Faisal
Problem name: Crossed Ladders
This problem is solved with the help of CROSSED LADDER theorem, which states
1/h1 + 1/h2 = 1/h.
You've to guess a width of path W. Now find h1(height of the Triangle 1) & h1.
With the help of the h1 and h2 find if W is greater or lesser to given C.
*/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int TC, cn = 0; cin>>TC;
    while(TC--){
        double x, y, c, h1, h2; cin>>x>>y>>c;

        double hi = min(x,y), lo = 0.0;
        for(int i=1; i<70; i++){
            double mid = lo + (hi - lo)/2;
            
            h1 = sqrt(x*x - mid*mid), h2 = sqrt(y*y - mid*mid);
            if((1/h1) + (1/h2) > 1/c)
                hi = mid;
            else
                lo = mid;
        }
        cout<<"Case "<<++cn<<": "<<fixed<<setprecision(7)<<hi<<"\n";
    }
    return 0;
}
