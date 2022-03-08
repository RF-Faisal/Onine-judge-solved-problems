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

class node{
public:
    int index;
    node *child[26];
};
node *root;
node* createNode(){
    node * u = new node;
    for(int i=0; i<26; ++i)
        u->child[i] = NULL;
    u->index = -1;
    return u;
}
void init(){
    root = createNode();
}
void createEdge(node* u, node*v, char ch){
    u->child[ch-'a'] = v;
}
bool insert(string str, int id){
    node *u = root;
    for(int i=0; i<str.size(); ++i){
        int idx = str[i] - 'a';
        
        if(u->child[idx] == NULL){
            node *v = createNode();
            createEdge(u, v, str[i]);
        }
        u = u->child[idx];
    }
    if(u->index != -1)
        return false;
    u->index = id;
    return true;
}
node *find(string str, node *u = root){
    for(int i=0; i<str.size(); ++i){
        int idx = str[i] - 'a';

        if(u->child[idx] == NULL) return NULL;
        u = u->child[idx];
    }
    return u;
}
void print(node* u=root, string str=""){
    if(u->index != -1){
        cout<<str<<'\n';
    }
    for(int i=0; i<26; ++i){
        char ch = 'a' + i;
        if(u->child[i] != NULL)
            print(u->child[i], str + ch);
    }
}
bool isLeaf(node *u){
    for(int i=0; i<26; ++i)
        if(u->child[i]) return false;
    return true;
}
bool isJunction(Node *u){
    if(u->EoW==1)    return true;
    if(isLeaf(u))    return false;
    return true;
}
void removeEdge(Node *u, char c, int d){
    if(d==0) return;
    int rp = relPos(c);
    Node *v = u->children[rp];
    u->children[rp] = NULL;
    free(v);
}
int delete(string key, Node *u=root, int i=0){
    if(u==NULL) return 0;
    if(i==key.size()){
        if(u->EoW==0) return 0;
        if(isLeaf(u)==false){
            u->EoW = 0;
            return 0;
        }
        return 1;
    }
    int r = relPos(key[i]);
    int d = delete(key, u->children[r],i+1);
    removeEdge(u, key[i], d);
    if(isJunction(u)==true)	d=0;
    return d;
}
bool isLeaf(node *u){
    for(int i=0; i<26; ++i)
        if(u->child[i]) return false;
    return true;
}
bool isJunction(Node *u){
    if(u->EoW==1)    return true;
    if(isLeaf(u))    return false;
    return true;
}
void removeEdge(Node *u, char c, int d){
    if(d==0) return;
    int rp = relPos(c);
    Node *v = u->children[rp];
    u->children[rp] = NULL;
    free(v);
}
int delete(string key, Node *u=root, int i=0){
    if(u==NULL) return 0;
    if(i==key.size()){
        if(u->EoW==0) return 0;
        if(isLeaf(u)==false){
            u->EoW = 0;
            return 0;
        }
        return 1;
    }
    int r = relPos(key[i]);
    int d = delete(key, u->children[r],i+1);
    removeEdge(u, key[i], d);
    if(isJunction(u)==true)	d=0;
    return d;
}


signed main(){
    FIO 
}
