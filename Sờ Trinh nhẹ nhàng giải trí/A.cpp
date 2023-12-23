#include <bits/stdc++.h>

using namespace std;

struct Node{
	Node* tree[256];
	bool end;
};

Node* newNode(){
	Node* N = new Node;
	for (int i = 0; i < 256; i++)
		N -> tree[i] = nullptr;
	N -> end = false;
	return N;
}

void insert(Node* root, string s){
	Node* v = root;
	for (int i = 0; i < s.size(); i++){
		if (!v -> tree[s[i]])
			v -> tree[s[i]] = newNode();
		v = v -> tree[s[i]];
	}
	v -> end = true;
}

bool find(Node* root, string s){
	Node* v = root;
	for (int i = 0; i < s.size(); i++){
		if (!v -> tree[s[i]])
			return false;
		v = v -> tree[s[i]];
		if (v -> end)
			return true;
	}
	return true;
}

void solve(){
	int n; cin >> n;
	Node* root = newNode();
	string s;
	bool flag = 1;
	for (int i = 1; i <= n; i++){
		cin >> s;
		if (find(root, s)) flag = 0; 
		insert(root, s);
	}
	cout << (flag? "YES\n": "NO\n");
}

int main(){
	int t; cin >> t;
	while (t--) solve();
	return 0;
}