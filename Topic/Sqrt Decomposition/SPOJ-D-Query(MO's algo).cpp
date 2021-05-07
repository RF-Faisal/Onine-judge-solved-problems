//https://www.spoj.com/problems/DQUERY/

#include<bits/stdc++.h>
using namespace std;
const int SIZE_1 = 1e6+10, SIZE_2 = 3e4+10;

class query{
public:
    int l, r, indx;
};

int block_size, cnt = 0;
int frequency[SIZE_1], a[SIZE_2];


void add(int indx){
    ++frequency[a[indx]];
    if(frequency[a[indx]] == 1) ++cnt;
}
void sub(int indx){
    --frequency[a[indx]];
    if(frequency[a[indx]] == 0) --cnt;
}

bool comp(query a, query b){
    if(a.l/block_size == b.l/block_size)
        return a.r < b.r;
    
    return a.l/block_size < b.l/block_size; 
}

signed main(){
    int n; cin>>n;
    for(int i=0; i<n; ++i) cin>>a[i];

    int q; cin>>q;
    int ans[q] = {};


    query Qur[q];
    for(int i=0; i<q; ++i){
        int l, r; cin>>l>>r;

        Qur[i].l = l-1;
        Qur[i].r = r-1;
        Qur[i].indx = i;
    }

    block_size = sqrt(q);
    sort(Qur, Qur+q, comp);

    int ML = 0, MR = -1;
    for(int i=0; i<q; ++i)
    {
        int L = Qur[i].l;
        int R = Qur[i].r;

        //fixing right pointer
        while(MR < R) add(++MR);
        while(MR > R) sub(MR--);

        //fixiing left pointer
        while(ML < L) sub(ML++);
        while(ML > L) add(--ML);

        ans[Qur[i].indx] = cnt;
    }

    for(int i=0; i<q; ++i) 
        cout<<ans[i]<<'\n';
}
