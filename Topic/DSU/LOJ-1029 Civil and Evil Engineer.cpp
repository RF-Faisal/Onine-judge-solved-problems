#include <bits/stdc++.h>
using namespace std;
#define int long long

struct graph{
    int uu, vv, ww;
};

bool comp_asc(graph a, graph b){
    return a.ww < b.ww;
}
bool comp_des(graph a, graph b){
    return a.ww > b.ww;
}

int par[102];
void init(int n){
    for(int i=0; i<=n; ++i) par[i] = i;
}
int find_par(int n){
    return (n==par[n])? n: par[n] = find_par(par[n]);
}
void join(int a, int b){
    int x = find_par(a), y = find_par(b);
    if(x != y) par[x] = y;
}

int kruskal(int n, vector<graph> &vec){
    int sum = 0, cnt = 0;
    
    for(int i=0; i<vec.size(); ++i){
        int u = vec[i].uu, v = vec[i].vv;

        if(find_par(u) != find_par(v)){
            join(u, v);
            sum += vec[i].ww;
            ++cnt;
            if(cnt == n) break;
        }
    }
    return sum;
}

signed main(){
    int tc; scanf("%d", &tc);
    for(int cn=1; cn<=tc; ++cn){
        int n; scanf("%d", &n);

        int u, v, w; 
        vector<graph> vec;
        while(scanf("%d%d%d", &u, &v, &w) and (u+v+w)){
            graph temp; 
            temp.uu = u, temp.vv = v, temp.ww = w;
            vec.push_back(temp);
        }
        
        sort(vec.begin(), vec.end(), comp_des);
        init(n);
        int maxi = kruskal(n, vec);
        
        sort(vec.begin(), vec.end(), comp_asc);
        init(n);
        int mini = kruskal(n, vec);

        if((mini+maxi)&1) printf("Case %d: %d/2\n", cn, mini+maxi);
        else printf("Case %d: %d\n", cn, (mini+maxi)/2);
    }   
}
