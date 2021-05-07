//problem link: https://open.kattis.com/problems/election
//topic : Expected Value

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define err 1e-15

double dp[103][103];//dp[confirmed votes][unknown votes]

signed main(){
    FIO 
    dp[0][0] = 1.0;
    for(int i=1; i<101; ++i){
        for(int j=0; j<=i; ++j){
            dp[i][j] += 0.5*dp[i-1][j]; //confirmed vote increased but the vote didn't go to my favour
            dp[i][j+1] += 0.5*dp[i-1][j]; //confirmed vote increased and went to my favour
        }
    }
    TC{
        int n, a, b, w; cin>>n>>a>>b>>w;
        int un_c = n - (a+b);

        int flag = 101;
        for(int i=0; i<=un_c; ++i){
            if(2*a + 2*i > n) {
                flag = i; break;
            }
        }

        double sum = 0;
        for(int i=flag; i<=un_c; ++i)   
            sum += dp[un_c][i];

        sum *= 100; sum -= err;

        if(sum > w) cout<<"GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
        else if(flag == 101) cout<<"RECOUNT!\n";
        else cout<<"PATIENCE, EVERYONE!\n";
    }
}
