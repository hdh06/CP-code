#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[256];
	bool end;
};

node* newNode(){
	node* n = new node;
	for (int i = 0; i < 256; i++)
		n -> tree[i] = nullptr;
	n -> end = false;
	return n;
}

void insert(node* root, string s){
	node* v = root;
	for (int x: s){
		if (!v -> tree[x])
			v -> tree[x] = newNode();
		v = v -> tree[x];
	}
	v -> end = true;
}

bool find(node* root, string s){
	node* v = root;
	for (int x: s){
		if (!v -> tree[x])
			return true;
		v = v -> tree[x];
		if (v -> end)
			return false;
	}
	return false;
}

void solve(){
	int n;
	cin >> n;

	node* tree = newNode();

	bool flag = 1;

	string t; while(n--){
		cin >> t;
		flag = find(tree, t);
		insert(tree, t);
	}

	cout << (flag? "YES\n": "NO\n");
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}