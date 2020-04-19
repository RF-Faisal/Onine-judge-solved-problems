#include<bits/stdc++.h>
 
#define LL long long
#define L long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t, tst;
    cin>>t;
    for(int tst=1; tst<=t; tst++){
        LL s, range1, range2, x, y;
        cin>>s;
        range1 = sqrt(s-1)+1;
        range2 = range1-1;
       
        LL k1 = range1*range1;
        LL k2 = range2*range2 + 1;
       
        bool closer = false;
        if(k1-s+1<=range1) {
            x = k1-s+1;
            closer = true;
        }
        else x = range1;
 
        if(closer) y = range1;
        else y = s-k2+1;
 
        if(!(range1&1)) swap(x,y);
 
        cout<<"Case "<<tst<<": "<<x<<' '<<y<<'\n';
    }
    return 0;
}
