#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    
    int tst, TC;
    cin>>TC;
    for(tst=1; tst<=TC; tst++){
        int n;
        cin>>n;
        vector<long>people(n+1);
        people[0]=-1;
        for(int i=1; i<=n; i++){
            cin>>people[i];
        }
        sort(people.begin(), people.end());
        long sum=0;
        for(int i=1; i<=n; i++){
            if((people[i]+i+1)<=n && people[i+people[i]+1]==people[i]){
                sum+=(people[i]+1);
                i += people[i];
                continue;
            }
            else if(people[i]==people[i+1] && i+1<=n) continue;
            sum+=(people[i]+1);
        }
        cout<<"Case "<<tst<<": "<<sum<<'\n';
    }
return 0;
}
