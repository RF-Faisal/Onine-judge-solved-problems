#include<bits/stdc++.h>
 
#define LL long long
#define L long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   
    int TC, tst;
    cin>>TC;
   
    vector<int>div(1001, 1), ans(1001);
    for(int i=2; i<=1000; i++){
        for(int j=2; j<=1000; j++){
            if(j%i==0) div[j]++;
        }
    }
    ans[1]=1;
    int x =2;
    int var = sqrt(1000)+1;
    for(int k=2; k<=var; k++){
        for(int l=1000; l>=2; l--){
            if(k==div[l]) {
                ans[x]=l;
                x++;
            }
        }        
    }
    for(tst = 1; tst<=TC; tst++){
        int n;
        cin>>n;
        cout<<"Case "<<tst<<": "<<ans[n]<<'\n';
    }
    return 0;
}
