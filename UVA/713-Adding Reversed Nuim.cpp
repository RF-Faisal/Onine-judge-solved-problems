#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

string rev(string s){
    int len = s.size(), i = 0;
    string op = "";

    while(true){
        if(s[i] == '0') ++i;
        else break;
    }
    for(; i<len; ++i){
        op += s[i];
    }
    return op;
}
string sum(string a, string b){
    int len_a = a.size(), len_b = b.size();
    if(len_b > len_a){ // len_a is always larger
        swap(a, b);
        swap(len_a, len_b);
    }

    string res = "";
    int carry = 0;

    for(int i=0; i<len_b; ++i){
        int bit_sum = a[i] - '0' + b[i] - '0' + carry;
        carry = bit_sum/10;
        char temp = (bit_sum%10) + '0';
        res.push_back(temp);
    }
    for(int i=len_b; i<len_a; ++i){
        int bit_sum = a[i] - '0' + carry;
        carry = bit_sum/10;
        char temp = (bit_sum%10) + '0';
        res.push_back(temp);
    }
    if(carry) 
        res.push_back(carry + '0');
    
    return rev(res);
}
signed main(){
    FIO TC{
        string a, b, a_, b_, res;  cin>>a>>b;

        cout<<sum(a, b)<<'\n';
    }     
}
