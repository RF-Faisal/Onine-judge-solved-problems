#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int tst;
    scanf("%d", &tst);
 
    for(int k=1; k<=tst; k++){
        long long n, a, b;
        scanf("%lld", &n);
 
        long long grid[2*n-1][n], dp[2*n-1][n];
        n = n-1;
 
        for(a=0; a<= 2*n; a++){
            for(b=0; b<=a; b++){
                scanf("%lld", &grid[a][b]);
   
                if((a+b)==(2*n)) break;
            }
        }
        dp[2*n][0]=grid[2*n][0];
 
        for(long long i=(2*n-1); i>=0; i--){
            for(long long j=0; j<=i; j++){
                if(i>=n && j==0){
                    dp[i][j]= grid[i][j]+dp[i+1][j];
                }
                else if(i>=n && (i+j)==2*n){
                    dp[i][j]=grid[i][j]+dp[i+1][j-1];
                    break;
                }
                else if(i>=n)
                    dp[i][j]= grid[i][j]+max(dp[i+1][j-1], dp[i+1][j]);
                else
                    dp[i][j]= grid[i][j]+max(dp[i+1][j], dp[i+1][j+1]);
            }
        }
 
        printf("Case %d: %lld\n", k,dp[0][0]);
 
    }
    return 0;
}
