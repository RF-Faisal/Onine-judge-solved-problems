#include<bits/stdc++.h>
 
#define LL long long
#define L long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
 
    double dp[1000009]={};//should be declared globally
    long j=1;
    long last_counted=1;
   
    int TC, tst;
    cin>>TC;
    for(tst = 1; tst<=TC; tst++){
        long n, base, ans;
        cin>>n>>base;
        long digits=0;
 
        if(n>last_counted){
            j = last_counted;
            for(; j<=n; j++){
                dp[j]= dp[j-1]+ log10(j);
            }
            last_counted = j;
        }
       
        ans = dp[n]/log10(base*1.0);
        cout<<"Case "<<tst<<": "<<ans+1<<'\n';
    }
    return 0;
}
