#include "bits/stdc++.h"
using namespace std;

int bin_to_dec(int n){
    int dec = 0, pow = 0;
    do{
        dec += (n%10) << pow++;
    }while(n/=10);
    
    return dec; 
}

int main(){
    int tc; scanf("%d", &tc);
    for(int cn=1; cn<=tc; ++cn)
    {
        int a1, b1, c1, d1, a2, b2, c2, d2;
        scanf("%d.%d.%d.%d", &a1, &b1, &c1, &d1);
        scanf("%d.%d.%d.%d", &a2, &b2, &c2, &d2);

        printf("Case %d: ", cn);
        if(a1==bin_to_dec(a2) and b1==bin_to_dec(b2) and c1==bin_to_dec(c2) and d1==bin_to_dec(d2))
            printf("Yes\n");
        else 
            printf("No\n");
    }
}
