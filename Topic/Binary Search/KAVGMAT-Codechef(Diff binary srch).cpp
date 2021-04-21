#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int tc; cin>>tc;
    for(int cn=1; cn<=tc; ++cn)
    {
        int n, m, k; cin>>n>>m>>k;
        int mat[n][m], adj_mat[n][m]; 
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>mat[i][j];
                adj_mat[i][j] = mat[i][j] + (j>0? adj_mat[i][j-1] : 0);
            }
        }
        for(int j=0; j<m; ++j){
            for(int i=1; i<n; ++i)
                adj_mat[i][j] += adj_mat[i-1][j];
        }

        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<m; ++j)
        //         cout<<adj_mat[i][j]<<' ';
        //     cout<<'\n';
        // }

        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int max_len = min(n-i, m-j);
                int l = 0, r = max_len+1, mid; 
             
                //l সর্বোচ্চ max_len-1 হতে পারে, কিন্তু সেখানে পৌছালে অবশ্যই পরের স্টেপে লুপ exit করতে হবে।
                //আবার সর্বশেষপ্রাপ্ত l এর মান ভ্যালিড রাখতে হবে। 
                //l <= (r = max_len) এই কন্ডিশন করলে sum চেক করত গিয়েে অ্যারে out of bound হয়ে যাবে 
                
                while(l<r-1){
                    mid = (r+l)/2;

                    int sum = adj_mat[i+mid-1][j+mid-1];
                    sum -= (i>0? adj_mat[i-1][j+mid-1]: 0);
                    sum -= (j>0? adj_mat[i+mid-1][j-1]: 0);
                    if(i and j) sum += adj_mat[i-1][j-1];

                    if(k > (sum/(mid*mid))) l = mid;
                    else r = mid; 
                }
                ans += max_len - l;
            }
        }
        cout<<ans<<'\n';
    }
}
