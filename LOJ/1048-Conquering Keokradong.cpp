#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, cn = 0; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        
        int camp[n+1+1], max_dis = 0, sum_dis = 0;
        for(int i=0; i<n+1; i++) {
            cin>>camp[i];
            max_dis = max(max_dis, camp[i]);
            sum_dis += camp[i];
        }

        int hi = sum_dis, lo = max_dis, min_dis_per_day, extra_days_left;
        while (lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            
            bool hobe = true;
            int day_cnt = 1, walk_per_day = 0, temp_sum = 0;
            for(int i=0; i<n+1; i++)
            {   
                temp_sum += camp[i];
                walk_per_day += camp[i];
                
                if(walk_per_day > mid)
                    day_cnt++, walk_per_day = camp[i];
                
                if(day_cnt > k+1){
                    hobe = false;
                    break;
                }
            }

            if(hobe){
                min_dis_per_day = mid;
                hi = mid-1;
            }
            else 
                lo = mid+1; 
        }
        cout<<"Case "<<++cn<<": "<<min_dis_per_day<<"\n";

        int dis_per_day = camp[0], streak = 1; 
        extra_days_left = n - k;
        camp[n+1] = 0;
        for(int i=1; i<n+1+1; i++)
        {   
            dis_per_day += camp[i];
            streak++;
            
            if(extra_days_left > 0){
                if(dis_per_day > min_dis_per_day or extra_days_left-(streak-2)==0)
                {
                    extra_days_left -= (streak-2);
                    cout<<dis_per_day - camp[i]<<"\n";
                    dis_per_day = camp[i];
                    streak = 1;
                }
            }
            else{        
                cout<<dis_per_day - camp[i]<<"\n";
                dis_per_day = camp[i];
                streak = 1;
            }
        }
    }
    return 0; 
}
