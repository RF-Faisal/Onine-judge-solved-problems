#include<bits/stdc++.h>
using namespace std;
const int MX = 1e8+2, SiZEM = 6e6+1;

unsigned mul_p[SiZEM];
vector<int> prime;
bitset<MX> visited;
void sieve(){
    prime.push_back(2);
    for(int i=3; i<MX; i+=2){
        if(visited[i]) continue;
        
        prime.push_back(i);
        if(1ll*i*i > MX) continue;
        for(int j=i*i; j<MX; j+= 2*i) visited[j] = true;
    }
}
unsigned int func(int n, int div){
    unsigned res = 1;
    n /= div;
    while(n /= div){
        res *= div;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve(); //cout<<prime.size()<<'\n';
    int siz = prime.size();
    mul_p[0] = 1;
    for(int i=1; i<=siz; ++i) mul_p[i] = mul_p[i-1] * prime[i-1];
    
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn){
        int n; cin>>n;
        
        int id_p = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
        unsigned lcm = mul_p[id_p];

        for(auto it: prime){
            if(it*it > n) break;
            lcm = lcm * func(n, it);
        }
        cout<<"Case "<<cn<<": "<<(unsigned)lcm<<'\n';
    }
}
