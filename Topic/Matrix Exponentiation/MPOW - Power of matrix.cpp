#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7; 
int m, n;

void mul(vector<vector<int>> &A, vector<vector<int>> &B){
    int res[m][m];

    for(int i=0; i<m; ++i){
        for(int j=0; j<m; ++j){
            res[i][j] = 0;
            
            for(int k=0; k<m; ++k) 
                res[i][j] = (res[i][j] + (A[i][k]*B[k][j]) % MOD) % MOD;
        }
    }
    for(int i=0; i<m; ++i)
        for(int j=0; j<m; ++j)
            A[i][j] = res[i][j];
}
void mat_expo(vector<vector<int>> &mat, vector<vector<int>> &ans){
    int n_ = n;

    while(n_){
        if(n_&1)
            mul(ans, mat);
        mul(mat, mat), n_>>=1;
    }
}

signed main(){
    int tc; cin>>tc; 
    while(tc--)
    {
        cin>>m>>n;

        vector<vector<int>> mat(m, vector<int> (m)), identity(m, vector<int> (m));
        for(int i=0; i<m; ++i){
            for(int j=0; j<m; ++j){
                cin>>mat[i][j];
                identity[i][j] = (i==j);
            }
        }

        mat_expo(mat, identity);

        for(int i=0; i<m; ++i){
            for(int j=0; j<m; ++j){
                cout<<identity[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}
