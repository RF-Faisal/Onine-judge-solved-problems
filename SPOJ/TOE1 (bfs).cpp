/*
Soln : The idea is to play the game as given input. If the given situation
can be reached then "yes" else "no".

cases to be kept in mind while playing:
    1. 'X' always goes first
    2. if 'X wins then no further moves haeppens
        similar for 'O''s wins
*/

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

/*  0 1 2
    3 4 5
    6 7 8
*/
bool won(string s){
    bool row = (s[0] != '.' and s[0]==s[1] and s[1]==s[2])
            or (s[3] != '.' and s[3]==s[4] and s[4]==s[5])
            or (s[6] != '.' and s[6]==s[7] and s[7]==s[8]);

    bool col = (s[0] != '.' and s[0]==s[3] and s[3]==s[6])
            or (s[1] != '.' and s[1]==s[4] and s[4]==s[7])
            or (s[2] != '.' and s[2]==s[5] and s[5]==s[8]);
    
    bool dia = (s[0] != '.' and s[0]==s[4] and s[4]==s[8])
            or (s[2] != '.' and s[2]==s[4] and s[4]==s[6]);
    
    return row or col or dia;
}
#define F first
#define S second

//X -> True, O -> False
bool bfs(string combi, bool player){
    string initial_board = ".........";
    queue<pair<string, bool>> Q;
    Q.push({initial_board, true});

    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        string in_game = cur.F;

        if(in_game == combi)
            return true;
        if(won(in_game)) 
            continue;

        for(int i=0; i<9; ++i)
        {
            if(in_game[i] == '.')
            {
                in_game[i] = cur.S? 'X': 'O';
                if(combi[i] == in_game[i]){
                    Q.push({in_game, cur.S^1});
                }
                in_game[i] = '.';
            }
        }
    }
    return false;
}
signed main(){
    FIO TC{
        string given = "", temp;
        
        for(int i=0; i<3; ++i){
            cin>>temp;
            given += temp;
        }

        cout<<(bfs(given, true)? "yes": "no")<<"\n";
    }   
}
