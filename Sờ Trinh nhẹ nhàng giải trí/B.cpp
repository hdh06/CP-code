#include <bits/stdc++.h>

using namespace std;

struct node{
	map<char, node*> tree;
	// node* tree[128];
};

node* newNode(){
	node* n = new node;
	// for (int i = 0; i < 128; ++i)
	// 	n -> tree[i] = nullptr;
	// n -> tree.clear();
	return n;
}

int insert(node* root, string &s, int i){
	node* v = root;
	int cnt = 0;
	for (char x = s[i]; i < s.size(); ++i, x = s[i]){
		if (!v -> tree[x]){
			v -> tree[x] = newNode();
			cnt++;
		}
		v = v -> tree[x];
	}
	return cnt;
}

//TLETLETLETLETLETLETLETLETLETLETLE

void solve(){
	string s; cin >> s;
	node* tree = newNode();

	int ans = 0;
	for (int i = s.size() - 1; i >= 0; --i)
		ans += insert(tree, s, i);
	
	cout << ans << "\n"; 
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}