#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[26];
	bool end;
};

node* newNode(){
	node* n = new node;
	for (int i = 0; i < 26; i++)
		n -> tree[i] = nullptr;
	n -> end = false;
	return n;
}

void insert(node* root, string s){
	node* v = root;
	for (int x: s){
		x -= 'a';
		if (!v -> tree[x])
			v -> tree[x] = newNode();
		v = v -> tree[x];
	}
	v -> end = true;
}

int const MOD = 1e9 + 7;
int dp[5002] = {1};

void xuly(node* root, string s, int x){
	node* v = root;
	for (int i = x; i < s.size(); i++){
		s[i] -= 'a';
		if (!v -> tree[s[i]])
			return;
		v = v -> tree[s[i]];
		if (v -> end) (dp[i] += dp[x - 1]) %= MOD;
	}
}

int main(){
	string s; cin >> s;
	s = ' ' + s;
	int n; cin >> n;

	node* tree = newNode();

	while (n--){
		string t; cin >> t;
		insert(tree, t);
	}

	for (int i = 1; i < s.size(); i++)
		xuly(tree, s, i);

	cout << dp[s.size() - 1];
	return 0;
}