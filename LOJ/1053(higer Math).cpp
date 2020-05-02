#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int TC, tst;
    cin>>TC;
    for(tst=1; tst<=TC; tst++){
        double a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a, a+3);
        cout<<"Case "<<tst<<": ";
        if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) cout<<"yes\n";
        else cout<<"no\n";
    }
}