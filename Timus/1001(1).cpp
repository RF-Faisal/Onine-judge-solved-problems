#include<iostream>
#include<math.h>
#include<stdio.h>

#define SIZE 128*1024

using namespace std;

int main(){
    double op[SIZE];
    long long i=0, j;
    while(~scanf("%lld", &j)){
        op[i++]= (double)sqrt(j*1.0);
    }
    while(i--){
        printf("%0.4lf\n", op[i]);
    }
    return 0;
}