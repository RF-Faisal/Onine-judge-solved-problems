#include "bits/stdc++.h"
using namespace std;
const int mx = 5e5+5;
const double err = 1e-7;

int n;
double x[mx], y[mx];

double find_dis(double x, double y, double dis){
    return sqrt((x - dis)*(x - dis) + y*y);
}
double max_dis(double mid){
    double maxi = 0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, find_dis(x[i], y[i], mid));
    }
    return maxi;
}

int main(){
    while(scanf("%d", &n) and n){
        for(int i=0; i<n; i++){
            // cin>>x[i]>>y[i];
            scanf("%lf%lf", &x[i], &y[i]);
        }

        double time = 0;
        double l = -2e5-5, r = 2e5+5;
        for(int i=0; i<100; i++){
            double m1 = l + (r-l)/3;
            double m2 = r - (r-l)/3;

            double t_1= max_dis(m1), t_2 = max_dis(m2);
            if(t_1 > t_2)
                l = m1, time = t_1;
            else 
                r = m2;
        }
        printf("%0.7lf %0.7lf\n", l+err, time+err);
    }
    return 0;
}
