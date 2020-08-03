#include "bits/stdc++.h"
using namespace std;

void func(char &c){ 
    if(c>='A' and c<= 'Z') {
        c = 'a' + c - 'A'; 
        return;
    }
    if(c>='a' and c<='z') 
        return;

    c = ' ';  
}
set<string> ans;

signed main(){
    string s, str;
    while(cin>>s){
        for(int i=0; i<s.size(); ++i)
            func(s[i]);
        
        stringstream kisu_ekta;
        kisu_ekta<<s;

        while(kisu_ekta>>str) ans.insert(str);
    }
    for(auto it: ans){
        cout<<it<<"\n";
    }
}
