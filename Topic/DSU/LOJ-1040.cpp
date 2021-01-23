#include <bits/stdc++.h>
using namespace std;

struct edge{
    int uu, vv, ww;
}temp;

bool cmp(edge a, edge b){
    return a.ww < b.ww;
}

int par[52];
int find_p(int n){
    return (par[n]==n)? n: par[n] = find_p(par[n]);
}
void join(int a, int b){
    int x = find_p(a), y = find_p(b);
    if(x != y) par[x] = y;
}
int kruskal(int n, vector<edge> &vec){
    int sum = 0, cnt = 0;
    for(auto itr=vec.begin(); itr!=vec.end(); ++itr){
        int x = (*itr).uu, y = (*itr).vv;
        if(find_p(x) != find_p(y)){
            join(x, y);
            sum += (*itr).ww;
            ++cnt;
        }
    }
    // cout<<cnt<<'\n';
    return (cnt+1==n? sum: -1);
}

signed main(){
    int TC; scanf("%d", &TC);
    for(int cn=1; cn<=TC; ++cn)
    {
        int n, sum = 0; scanf("%d", &n);
        vector<edge> vec;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                int wei; scanf("%d", &wei); sum += wei;
                temp.uu = i, temp.vv = j, temp.ww = wei;
                if(i!=j and wei>0)vec.push_back(temp);
            }
        }
        sort(vec.begin(), vec.end(), cmp);
        // for(auto itr=vec.begin(); itr!=vec.end(); ++itr) 
        //     cout<<(*itr).ww<<' ';
        for(int i=0; i<=n; ++i) par[i] = i;
        int ans = kruskal(n, vec);
        printf("Case %d: %d\n", cn, (ans<0)? -1:sum - ans);
    }
}
