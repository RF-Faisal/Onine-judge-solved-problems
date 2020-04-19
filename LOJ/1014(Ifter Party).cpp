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
    for(tst = 1; tst<=TC; tst++){
        L p, l;
        vector<L> lala;
        cin>>p>>l;
       
        L div = p-l;
        L sqrot = sqrt(div);
 
        cout<<"Case "<<tst<<":";
       
        if(div<=l) cout<<" impossible";
        else{
            for(L i=1; i<=sqrot; i++){
                if(div%i==0){
                    if(div/i==i && i>l) {
                        cout<<' '<<i;
                    }
                    else if(i<l) lala.push_back(div/i);
                    else{
                        if(i>l) cout<<' '<<i;
                        lala.push_back(div/i);
                    }
 
                }
            }
            for(L j = lala.size()-1; j>=0; j--){
                if(lala[j]>l) cout<<' '<<lala[j];
            }
        }
        cout<<'\n';
    }
    return 0;
}
