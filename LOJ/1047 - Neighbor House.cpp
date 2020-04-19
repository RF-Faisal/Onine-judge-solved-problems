#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int cases;
    scanf("%d", &cases);
 
    for(int tst=1; tst<=cases; tst++){
        int n;
        scanf("%d", &n);
        int house[n][3], dp[n][3];
        n=n-1;
 
        for(int i=0; i<n; i++){
            scanf("%d%d%d", &house[i][0],&house[i][1], &house[i][2]);
        }
        scanf("%d%d%d", &dp[n][0],&dp[n][1], &dp[n][2]);
 
        for(int i=(n-1); i>=0; i--){
            dp[i][2]=house[i][2]+ min(dp[i+1][0], dp[i+1][1]);
            dp[i][1]=house[i][1]+ min(dp[i+1][2], dp[i+1][0]);
            dp[i][0]=house[i][0]+ min(dp[i+1][1], dp[i+1][2]);
        }
        int ans = min(dp[0][0], min(dp[0][1],dp[0][2]));
 
        printf("Case %d: %d\n", tst, ans);
    }
return 0;
}
