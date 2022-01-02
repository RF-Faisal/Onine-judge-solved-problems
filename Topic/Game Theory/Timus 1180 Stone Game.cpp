#include<bits/stdc++.h>
using namespace std;

signed main(){
    string s; cin>>s;
    int n = 0;
    for(int i=0; i<s.size(); ++i)
        n += s[i]-'0';
    
    if(n%3) cout<<"1\n"<<n%3<<'\n';
    else cout<<"2\n";
}
