#include"bits/stdc++.h"
using namespace std;
typedef long long LL;

int main(){
    LL step, mod;
    while (~scanf("%lld%lld", &step, &mod))
    {
        LL flag = abs(mod - step);
        bool ok = true, maap[mod] = {0};
        for(LL i=0, j=0; i<mod; i++, j += flag)
        {   
            // j %= mod; dielo pera nai
            LL var = (j+step)%mod;
            if(!maap[var])
                maap[var] = true;
            else{
                ok = false;
                break;
            }
        }
        string st = to_string(step);
        string mo = to_string(mod);

        for(int j=0; j< 10 - st.size(); j++)
            printf(" ");
        printf("%d", step);

        for(int j=0; j< 10 - mo.size(); j++)
            printf(" ");
        printf("%d", mod);

        for(int j=1; j<5; j++)
            printf(" ");

        if(ok) printf("Good Choice\n\n");
        else printf("Bad Choice\n\n");
    }
    return 0;
}