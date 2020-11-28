#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MX = 2e7+2;
vector<int> nth_prime;
vector<pair<int, int>> twin;
bitset<MX> visited; 
void optimized_prime(){
    nth_prime.push_back(2);
    for(int i=3; i<MX; i+=2){
            if(visited[i]) 
                continue;
            nth_prime.push_back(i);
            if(1ll*i*i > MX) 
                continue;
            for(int j = i*i; j< MX; j+= i+i)
                visited[j] = true;
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    optimized_prime();
    auto itr = nth_prime.begin(); ++itr;
    for(; itr != nth_prime.end(); ++itr){
        if(*itr - *(itr-1) == 2) twin.push_back({*(itr-1), *itr});
    }
    
    int var;
    while(cin>>var){
        cout<<'('<<twin[var-1].first<<", "<<twin[var-1].second<<")\n";
    }
}
