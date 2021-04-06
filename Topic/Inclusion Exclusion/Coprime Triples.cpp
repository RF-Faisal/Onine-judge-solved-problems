//problem link: https://www.codechef.com/problems/COPRIME3

/******************** Solution Idea *********************
1. First used frequency array to count the frequency of given numbers. 
2. Then counted how many multiples each numbers(from 1 to 1e6) have.
3. Then calculated how many triples possible with a common divisor i 
   for each i(1 to 1e6)
4. Then iterated over i(1e6 to 1) finding the count GCD of each i by 
   excluding GCD count of bigger multiplers of i
5. GCD count of i == 1 is the ans since at the 3nd step it stored the 
   possible number of triples and in the 5th step we excluded every triples 
   that has a GDC > 1.
*/


/******************Code Starts here******************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
#define CN cout<<"Case "<<cn<<": "

const int MX = 1e6+1;
int freq[MX], same_gcd_cnt[MX];

int nCr(int n){
    return (n > 2? (n*(n-1)*(n-2))/6 : 0);
}

signed main(){
    FIO int n, var; cin>>n;
    for(int i=1; i<=n; ++i) cin>>var, ++freq[var];

    for(int i=1; i<MX; ++i){
        for(int j=i; j<MX; j += i)
            same_gcd_cnt[i] += freq[j]; 

        same_gcd_cnt[i] = nCr(same_gcd_cnt[i]);
    }

    for(int i=MX; i>0; --i)
        for(int j=(i<<1); j<MX; j += i)
            same_gcd_cnt[i] -= same_gcd_cnt[j];
    
    cout<<same_gcd_cnt[1]<<'\n';
}
