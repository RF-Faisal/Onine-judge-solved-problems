#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int SIZE = 1e6+2;

vector<int> div_cnt[SIZE], adj[SIZE];
bitset<SIZE> vis;

vector<int> nth_prime;
bitset<SIZE> visited; 
void optimized_prime(){
    nth_prime.push_back(2);
    for(int i=3; i<SIZE; i+=2){
            if(visited[i]) 
                continue;
            nth_prime.push_back(i);
            if(1ll*i*i > SIZE) 
                continue;
            for(int j = i*i; j< SIZE; j+= i+i)
                visited[j] = true;
    }
}

void init(){
    div_cnt[1].push_back(1);
    for(int i=1; i<SIZE; ++i){
        int temp = i;
        for(int j=0; nth_prime[j]*nth_prime[j] <=temp; ++j){
            while(temp % nth_prime[j] == 0){
                temp /= nth_prime[j];
            }
            if(i%nth_prime[j] == 0) div_cnt[i].push_back(nth_prime[j]);
        }
        if(temp > 1) div_cnt[i].push_back(temp);
    }
}

void dfs(int node){
    vis[node] = true;
    for(int child: adj[node]){
        if(!vis[child])
            dfs(child);
    }
}

signed main(){
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    optimized_prime();
    init();

    for(int cn=1; cn<=tc; ++cn)
    {
        int n; cin>>n;
        int a[n];
        int cnt = 0;

        for(int i=0; i<n; ++i){
            cin>>a[i];

            if(a[i]==1){
                ++cnt; continue;
            }
            if(div_cnt[a[i]].size() == 1) {
                adj[div_cnt[a[i]][0]].push_back(div_cnt[a[i]][0]);
            }
            else{
                for(int j=1; j<div_cnt[a[i]].size(); ++j){
                    adj[div_cnt[a[i]][j]].push_back(div_cnt[a[i]][j-1]);
                    adj[div_cnt[a[i]][j-1]].push_back(div_cnt[a[i]][j]);
                }
            }
            vis_set[a[i]] = true;
        }

        for(int i=1; i<SIZE; ++i){
            if((!adj[i].empty()) and !vis[i])
                ++cnt, dfs(i);// cout<<i<<' ';
        }            

        cout<<"Case "<<cn<<": "<<cnt<<'\n';
        
        for(int i=1; i<SIZE; ++i){
            adj[i].clear();
            vis[i] = false;
        }
    }
}
