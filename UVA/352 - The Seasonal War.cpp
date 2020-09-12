#include "bits/stdc++.h"
using namespace std;

int visited[26][26], n, cn;
string s[25];

void dfs(int x, int y){
    if(x<0 or y<0 or x>=n or y>=n)
        return;
    if(visited[x][y] or s[x][y]=='0')
        return;

    visited[x][y] = 1;
    for(int i=-1; i<=1; i++)
        for(int j=-1; j<=1; j++)
            dfs(x+i, y+j);
}

int main(){ 
    while(cin>>n){
        memset(visited, 0, sizeof(visited));
        // string s[n]; 
        for(int i=0; i<n; i++) {
            cin>>s[i];
        }

        int con_com = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i][j]=='1' and visited[i][j]==0){
                    dfs(i, j);
                    con_com++;
                }
            }
        }
        cout<<"Image number "<<++cn<<" contains "<<con_com<<" war eagles.\n";
    }   
}