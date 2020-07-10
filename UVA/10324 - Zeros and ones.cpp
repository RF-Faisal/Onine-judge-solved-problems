#include "bits/stdc++.h"
typedef long long LL;
using namespace std;

int main(){
    int cn = 0;
    string s;
    while (cin>>s)
    {
        LL siz = s.size();
        LL pre[siz+1] = {}, val = 0; //pre[0] = s[0] - '0';
        for(int i=1; i<siz; i++){
            if(s[i] != s[i-1]){
                ++val;
            }
            pre[i] = val;
        }
        LL q, l, r;
        cin>>q;
        cout<<"Case "<<++cn<<":\n";
        while(q--){
            cin>>l>>r;
            cout<<(pre[l]==pre[r]? "Yes\n": "No\n");
        }
    }
    return 0;    
}