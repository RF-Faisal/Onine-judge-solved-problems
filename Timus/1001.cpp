#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> n;
    double ara;
    //while(cin>>ara){
    while((scanf("%lf", &ara))!= EOF){//this is too faster than previous line
        double a;
        a = sqrt(ara);
        n.push_back(a);
    }
    int size = n.size();

    while(size--){
        printf("%.4lf\n", n[size]);
    }
    return 0;
}