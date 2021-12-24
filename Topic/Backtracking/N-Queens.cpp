//https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/n-queensrecursion-tutorial/

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\CP\Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

int board[12][12];
int n;

bool isSafe(int col, int row){
    for(int i=0; i<n; ++i){
        if(board[i][col]) return false; //up-down
        if(board[row][i]) return false; //left-right

        //top-left diagonal
        if(row-i>=0 and col-i>=0 and board[row-i][col-i]) return false; 
        if(row+i<n and col+i<n and board[row+i][col+i]) return false;
        
        //top-right diagonal
        if(row-i>=0 and col+i<n and board[row-i][col+i]) return false;
        if(row+i<n and col-i>=0 and board[row+i][col-i]) return false;
    }
    return true;
}
bool nQueen(int row){
    if(row==n) return true;

    for(int col=0; col<n; ++col){
        if(isSafe(col, row)){
            board[row][col] = 1;
            if(nQueen(row+1)) 
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}
signed main(){
    FIO cin>>n;

    if(!nQueen(0)) 
        cout<<"Not possible\n";
    else{
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                cout<<board[i][j]<<' ';
            cout<<'\n';
        }
    }
}
