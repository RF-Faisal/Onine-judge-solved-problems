#include "bits/stdc++.h"
using namespace std;

int month[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

bool isLY(int y){
    if(y%400==0) return 1;
    else if(y%100==0) return 0;
    else if(y%4==0) return 1;
    return 0;
}

int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n;
    while (scanf("%d", &n) and n)
    {
        int d[n], m[n], y[n], c[n], nth_day[n] = {0};
        for(int i=0; i<n; i++){
            scanf("%d%d%d%d", &d[i], &m[i], &y[i], &c[i]);
            
            if(isLY(y[i]) and m[i]>2) 
                nth_day[i]++;
            nth_day[i] += d[i] + month[m[i]];
            // cout<<' '<<nth_day[i]<<' ';
        }

        int day_cnt = 0, tot_cost = 0;
        for(int i=1; i<n; i++)
        {
            if(y[i] == y[i-1] and nth_day[i] - nth_day[i-1] == 1)
                day_cnt++, tot_cost += c[i] - c[i-1];
            else if(y[i] == y[i-1] + 1 and ((m[i]==1 and m[i-1]==12) and (d[i]==1 and d[i-1]==31)))
                day_cnt++, tot_cost += c[i] - c[i-1];
        }
        printf("%d %d\n", day_cnt, tot_cost);
    }
    return 0;
}