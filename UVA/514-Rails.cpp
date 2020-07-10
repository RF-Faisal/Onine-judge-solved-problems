#include "bits/stdc++.h"
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin>>n and n)
    {
        while(1)
        {
            int target[n+1], A = 1;
            stack<int> s;
            
            cin>>target[1];
            if(!target[1]) break;

            for(int i=2; i<=n; i++)
                cin>>target[i];
            
            for(int i=1; i<=n; i++)
            {
                if(s.empty()) 
                    s.push(A++);
                while(s.top() != target[i] and A <= n){
                    s.push(A++);
                }
                if(s.top() == target[i]) 
                    s.pop();
            }

            cout<<(s.size()==0? "Yes\n": "No\n");
        }
        cout<<"\n";            
    }
    return 0;
}