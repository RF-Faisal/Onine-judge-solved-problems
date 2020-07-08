#include<bits/stdc++.h>
using namespace std;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string a, b;
    while(cin>>a>>b){
        // cin>>b;
        int len_a = a.size(), len_b = b.size();

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int res_len = len_a + len_b;
        int res[res_len] = {};
        for(int i=0; i<len_a; i++)
        {
            int temp_a = a[i] - '0';
            for(int j=0; j<len_b; j++)
            {
                int temp_b = b[j] - '0';
                int temp_res = temp_a * temp_b;

                res[i+j] += temp_res;
                res[i+j+1] += res[i+j]/10;
                res[i+j] %= 10;
            }
        }
        int indx = res_len - 1;
        for(; indx>0; indx--) if(res[indx]) break; 
        for(int i = indx; i>=0; i--) 
            cout<<res[i];
        cout<<"\n";
    }
    return 0;
}
