#include<bits/stdc++.h>
using namespace std;
const int MX = 310;

int vis_time[MX][MX];

double func(int a, int b){
    if(a == b) return 1;
    if(vis_time[a][b] == 100) return 1;

    ++vis_time[a][b];

    double res;
    if(a > b) res = 1 + func(a-b, b+b)*0.5;
    else res = 1 + func(a+a, b-a)*0.5;

    return res;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;

    for(int cn=1; cn<=tc; ++cn)
    {
        for(int i=0; i<MX; ++i)
            for(int j=0; j<MX; ++j)
                vis_time[i][j] = 0;
                
        int a, b; cin>>a>>b;
        double exp = func(a, b);
        double win = (double)a/(double)(a+b);

        cout<<fixed<<setprecision(7);
        cout<<"Case "<<cn<<": "<<exp<<' '<<win<<'\n';
    }
}
