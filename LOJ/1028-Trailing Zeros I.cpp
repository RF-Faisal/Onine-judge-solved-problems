#include<bits/stdc++.h>

#define SIZE 1000003
using namespace std;

vector<int> prime; // Stores generated primes
char sieve[SIZE];  // 0 means prime
void primeSieve(int n) {
    sieve[0] = sieve[1] = 1; // 0 and 1 are not prime

    prime.push_back(2); // Only Even Prime
    for (int i = 4; i <= n; i += 2)
        sieve[i] = 1; // Remove multiples of 2

    int sqrtn = sqrt(n);
    for (int i = 3; i <= sqrtn; i += 2) {
        if (sieve[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i)
                sieve[j] = 1;
        }
    }

    for (int i = 3; i <= n; i += 2)
        if (sieve[i] == 0)
            prime.push_back(i);
}
int divCount(long long n){
    int count = 1;
    
    for(int i=0; i<prime.size(), prime[i]<=sqrt(n); i++){
        if(!(n%prime[i])){
            int power = 1;
            while(!(n%prime[i])){
                n /= prime[i];
                power ++;
            }
            count *= power;
        }
    }
    if(n>1) count *= 2;
    return count;
}
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    primeSieve(SIZE);
    int TC, tst=0;
    scanf("%d", &TC);
    while(TC--){
        long long n;
        scanf("%lld", &n);
        printf("Case %d: %lld\n", ++tst, divCount(n) - 1);
    }
    return 0;
}
