#include<iostream>
#include<cmath>
#include<iomanip>//setprecision

#define PI acos(-1.0)

using namespace std;


int main(){
    int TC, tst;
    cin>>TC;
    for(tst=1; tst<=TC; tst++){
        double R, n, r;
        cin>>R>>n;

        double sine = sin(PI/n);
        sine = 1/sine;

        r = R/(sine+1);

        printf("Case %d: %0.7lf\n", tst, r);
        cout<<"Case "<<tst<<": "<< fixed << setprecision(7) <<r<<endl;
    }
    return 0;
}
