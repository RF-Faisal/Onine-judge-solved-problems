#include "iostream"
using namespace std;

int main(){
    long long n, m, c, ans; 

    while(cin>>n>>m>>c){
        if(n+m+c==0) break;

        n -= 7, m -= 7;
        ans = n*m/2;
        if(n&1 and m&1 and c==1) 
            ans++;
        
        cout<<ans<<"\n";
    }
    return 0;
}