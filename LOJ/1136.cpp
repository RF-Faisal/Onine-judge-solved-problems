#include<iostream>
using namespace std;

int TC, tst;
int main(){
    ios_base::sync_with_stdio(false);
    
    cin>>TC;
    while (TC--)
    {
        long long a, b, ans;
        cin>>a>>b;
        
        a--;
        ans = 2*b/3 - 2*a/3;

        cout<<"Case "<<++tst<<": "<<ans<<endl;
    }
    return 0;
}