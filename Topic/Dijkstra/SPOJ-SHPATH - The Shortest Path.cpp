#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

class Node{
public:
    int uu, ww;
    
    Node(int uu, int ww){
        this->uu = uu;
        this->ww = ww;
    }
    Node(){}

    bool operator <(const Node &rt) const{
        return ww > rt.ww;
    }
};
const int MX = 1e4+2, INF = 1e9+2;

signed main(){
    FIO TC{
        int n; cin>>n;
        map<string, int> mp;
        vector<int> adj[MX], wei[MX];

        for(int i=1; i<=n; ++i){
            string city; cin>>city;
            mp[city] = i;

            int m; cin>>m;
            for(int j=0; j<m; ++j){
                int v, w; cin>>v>>w;

                adj[i].push_back(v);
                // adj[v].push_back(i);
                wei[i].push_back(w);
                // wei[v].push_back(w);
            }
        }

        int r; cin>>r;
        for(int i=1; i<=r; ++i){
            string ss, dd; cin>>ss>>dd;
            int src = mp[ss], des = mp[dd];

            vector<int> dis(n+1, INF);
            priority_queue<Node> pq;
            dis[src] = 0;
            pq.push(Node(src, 0));
            
            while(!pq.empty()){
                Node cur = pq.top();
                pq.pop();

                if(cur.uu == des) break;
                int u = cur.uu, v, c;
                for(int j=0; j<adj[u].size(); ++j){
                    v = adj[u][j];
                    c = wei[u][j];

                    if(dis[v] > dis[u] + c){
                        dis[v] = dis[u] + c;
                        pq.push(Node(v, dis[v]));
                    }
                }
            }
            cout<<dis[des]<<'\n';
        }
    }
}
