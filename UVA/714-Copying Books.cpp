#include<bits/stdc++.h>
using namespace std;

long long m, k;
long long book[505] = {};
bool check(long long mid)
{   
    bool hobe;
    long long assign_page = 0, sc_cnt = 1;
    for(int i=0; i<m; i++)
    {
        assign_page += book[i];
        if(assign_page > mid){
            sc_cnt++;
            assign_page = book[i];
        }
        if(sc_cnt > k)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long tc; cin>>tc;
    while(tc--){
        cin>>m>>k;

        long long max_pages = 0, tot_pages = 0;
        for(int i=m-1; i>=0; i--){
            cin>>book[i];
            max_pages = max(max_pages, book[i]);
            tot_pages += book[i];
        }

        long long hi = tot_pages, lo = max_pages, highest_pages;
        while(hi >= lo){
            long long mid = lo + (hi-lo)/2;
            
            if(check(mid))
                highest_pages = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }

        long long temp_tot = 0, seg = 1;
        long long soln[m+k-1], indx = 0;
        for(int i=0; i<m; i++)
        {   
            temp_tot += book[i];
            if(temp_tot > highest_pages or (m-i)==(k-seg)){
                soln[indx++] = -1;
                seg++;
                temp_tot = book[i];
            }
            soln[indx++] = book[i];
        }

        for(int i=m+k-2; i>0; i--){
            if(soln[i] == -1) cout<<"/ ";
            else cout<<soln[i]<<" ";
        }
        cout<<soln[0]<<"\n";
    }
    return 0;
}
