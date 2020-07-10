#include "iostream"
using namespace std;
typedef long long LL;

LL modexp(LL B, LL P, LL M){
    LL res = 1;
    B %= M;
    while(P){
        if(P&1) res = (res*B)%M;
        B = (B*B)%M, P /= 2;
    }
    return res;
}

int main(){
    LL b, p, m;
    while (cin>>b>>p>>m)
    {
        cout<<modexp(b, p, m)<<"\n";
    }    
}