#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int TC, tst;
    cin>>TC;
    for(tst =1; tst<= TC; tst++){
        int me, lift;
        cin>>me>>lift;
        int ans = abs(me-lift)*4;
        ans += 3*3;
        ans += 5*2;
        ans += me*4;
        cout<<"Case "<<tst<<": "<<ans<<endl;
    }
}