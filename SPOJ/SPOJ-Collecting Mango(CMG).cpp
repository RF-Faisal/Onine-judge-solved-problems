#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn)
    {
        int n, mango; char c; 
        cin>>n; cin.ignore();

        stack<pair<int, int>> stk;
        int maxi = -1;

        cout<<"Case "<<cn<<":\n";

        for(int i=0; i<n; ++i){
            cin>>c;

            if(c == 'A'){
                cin>>mango; cin.ignore();
                maxi = max(maxi, mango);
                stk.push({mango, maxi});
            }
            else if(c == 'R'){
                if(!stk.empty()){
                    stk.pop();
                }
                if(stk.empty()) maxi = -1;
                else maxi = stk.top().second;
            }
            else{
                if(stk.empty())
                    cout<<"Empty\n";
                else 
                    cout<<stk.top().second<<"\n";
            }
        }
    }
}
