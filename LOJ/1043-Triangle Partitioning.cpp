/*
Problem link : http://lightoj.com/volume_showproblem.php?problem=1043&language=english&type=pdf
This can be solved in two ways. Basic geometry or using BISECTION method. Here I used the second way.
*/

#include<bits/stdc++.h>
using namespace std;

double AB, BC, CA, area_ABC;
double Find_Area(double a, double b, double c){
    double s = (a+b+c)/2;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

double Find_Ratio(double AD){
    double ratio = AD/AB;
    double AE = ratio * CA, ED = ratio * BC;
    return (Find_Area(AD, AE, ED)/area_ABC);
}

int main(){
    ios_base::sync_with_stdio(false);
    int tc, cn = 0; cin>>tc;
    while(tc--){
        double given_ratio;
        cin>>AB>>BC>>CA>>given_ratio;
        given_ratio = given_ratio/(1+given_ratio);
        area_ABC = Find_Area(AB, BC, CA);

        double hi = AB, lo = 0.0;
        for(int i=0; i<70; i++){
            double mid = lo + (hi-lo)/2;
            
            if(Find_Ratio(mid) > given_ratio)
                hi = mid;
            else 
                lo = mid;
        }
        double AD = hi;
        cout<<"Case "<<++cn<<": "<<fixed<<setprecision(7)<<AD<<"\n";
    }
    return 0;
}
