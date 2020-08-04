#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("q", "r", stdin);
    freopen("x", "w", stdout);
    int tc; cin>>tc; cin.ignore();
    while(tc--){
        stack<char> parenthesis;
        string s; getline(cin, s);

        bool ok = true;
        for(int i=0; i<s.size() and ok; ++i)
        {
            if(s[i] == '(' or s[i]=='[') parenthesis.push(s[i]);
            else if(!parenthesis.empty()){
                if(parenthesis.top() == '(' and s[i] != ')')
                    ok = false;
                else if(parenthesis.top() == '[' and s[i] != ']')
                    ok = false;
                else 
                    parenthesis.pop();
            }
            else if((s[i]==']' or s[i]==')') and parenthesis.empty())
                ok = false;
        }
        cout<<(ok and parenthesis.empty()? "Yes\n": "No\n");
    }
    return 0;
}
