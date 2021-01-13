#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n, m; cin>>n>>m;
        
        int a[n], last = n; for(int &i: a) cin>>i;
        do{
            if(a[last-1] != last) break;
        }while(last>1 and --last);
        
        double pos = last > 1;
        while(m--){
            int ri; double pi; cin>>ri>>pi;
            if(ri >= last) pos *= (1 - pi);
        }
        cout<<fixed<<setprecision(8)<<1-pos<<'\n';
    }
    return 0;
}
