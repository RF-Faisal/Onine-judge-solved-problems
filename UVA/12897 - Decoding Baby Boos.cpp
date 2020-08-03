#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin>>tc;
    while(tc--)
    {
        string s; cin>>s;
        int r; cin>>r;
        char a[r], b[r];

        map<char, char> sub;
        for(char ch = 'A'; ch <= 'Z'; ++ch)
            sub[ch] = ch;

        for(int i=0; i<r; ++i)
            cin>>a[i]>>b[i];

        for(int i=r-1; i>=0; --i)
            sub[b[i]] = sub[a[i]];

        for(int i=0; i<s.size(); ++i){
            if(s[i] == '_') cout<<s[i];
            else cout<<sub[s[i]];
        }
        cout<<"\n";
    }    
}
