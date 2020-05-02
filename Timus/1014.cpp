#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define LL long long 

int main(){
    LL n;
    cin>>n;
    string ans;
    bool possible = true;

    if(n==0) cout<<"10\n";
    else if(n==1) cout<<"1\n";
    else{
        while (n>1)
        {
            int var;
            char c;
            for(var = 9; var>= 1; var--){
                if(n%var==0){
                    break;
                }
            }
            if(var == 1) {
                possible = false;
                break;
            }
            n /= var;
            c = '0' + var;
            ans += string(1, c);
        }
        reverse(ans.begin(), ans.end());
        if(possible) cout<<ans<<'\n';
        else cout<<"-1\n";
    }

    return 0;
}
