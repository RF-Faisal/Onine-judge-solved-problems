#include<bits/stdc++.h>
 
using namespace std;
int main(){
    int tst, TC;
    cin>>TC;
    for(tst=1; tst<=TC; tst++){
        long b, div=0, i=0;
        string a;
        cin>>a>>b;
       
        if(a[0]=='-')i=1;
        for(; i<a.size(); i++){
            div = div*10+(a[i]-'0');
            div = div%b;
        }
        cout<<"Case "<<tst<<": ";
        if(div==0) cout<<"divisible\n";
        else cout<<"not divisible\n";
    }
    return 0;
}
