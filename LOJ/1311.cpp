#include<iostream>

using namespace std;

int tst, TC;
int main(){
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>TC;
    while(TC--){
        double v1, v2, v3, a1, a2, t, d, d_bird;
        cin>>v1>>v2>>v3>>a1>>a2;

        t = max(v2/a2, v1/a1);
        d_bird = v3 * t;
        d = ((v1*v1/a1)+(v2*v2/a2))/2;

        printf("Case %d: %.7lf %.7lf\n", ++tst, d, d_bird);
    }
}
