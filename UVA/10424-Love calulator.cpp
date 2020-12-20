#include<bits/stdc++.h>
using namespace std;

int func(int n){
    int res = 0;
    while(n){
        res += n%10;
        n /= 10;
    }
    if(res/10) return func(res);
    return res;
}
int add(char c[]){
    int sum = 0;
    for(int i=0; c[i] != NULL; ++i)
        sum += (c[i]>='a' and c[i]<='z'? c[i]-'a'+1: (c[i]>='A' and c[i]<='Z'? c[i]-'A'+1: 0));
    return sum;
}

signed main(){
    char s1[26], s2[26], c;
    while(gets(s1)){
        gets(s2);

        int sum1 = add(s1), sum2 = add(s2);
        int r1 = func(sum1), r2 = func(sum2);
        double r = (r1>r2? (double)r2/r1: (double)r1/r2);

        printf("%0.2lf %%\n", r*100);
    }
}