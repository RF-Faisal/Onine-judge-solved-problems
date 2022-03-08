#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/media/faisal/New Volume/CP/Debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

const int N = 2;
struct Node{
	int count;
	Node *child[N];
};
Node *root;
Node *createNode(){
	Node *n = new Node[2];	
	n->count = 0;
	for(int i=0; i<N; ++i)
		n->child[i] = NULL;
	return n;
} 
void createEdge(Node *u, Node *v, char c='0'){
	int id = c - '0';
	id %= 2;
	u->child[id] = v;
}
void init(){
	root = createNode();
}
void insert(string s, int inc){
	Node *u = root;
	int len = s.size();

	for(int i=len-1; i>=0; --i){
        char c = (int)s[i];
        int index = (int)c - '0';
        index %= 2;

        Node *v = createNode();
        if(u->child[index]==NULL) createEdge(u, v, c);
        u = u->child[index];		
	} 
	for(int i=len; i<18; ++i){
		int index = 0;
        Node *v = createNode();
        if(u->child[index]==NULL) createEdge(u, v);
        u = u->child[index];				
	}
	u->count += inc;
}
int src(string s, Node *u=root){
	int len = s.size();
	for(int i=len-1; i>=0; --i){
		int idx = s[i]-'0';
		idx %= 2;

        if(u->child[idx] == NULL) return 0;
		u = u->child[idx];
	}
	for(int i=len; i<18; ++i){
        if(u->child[0] == NULL) return 0;
		u = u->child[0];
	}
	return u->count;
}
signed main(){
	FIO int t; cin>>t;
	init();
	while(t--){
		string c, s;
		cin>>c>>s;

		if(c == "+") insert(s, 1);
		else if(c == "-") insert(s, -1);
		else cout<<src(s)<<'\n';
	}
}
