#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1122
#endif

using namespace std;

typedef long long ll;

int const N = 5001;

int n, a , b;
string s;
ll dp[N];

struct Node{
	Node* tree[26];
	int min_pos = INT_MAX;
	
	Node(){
		fill(tree, tree + 26, nullptr);
	}
};

void insert(Node* root, string &s, int i){
	Node* v = root;
	for (int j = i; j >= 1; j--){
		if (!v -> tree[s[j] - 'a'])
			v -> tree[s[j] - 'a'] = new Node;
		v = v -> tree[s[j] - 'a'];
		v -> min_pos = min(v -> min_pos, i);
	}
}

void get(Node* root, string &s, int i){
	Node* v = root;
	for (int j = i; j >= 1; j--){
		if (!v -> tree[s[j] - 'a'])
			return;
		v = v -> tree[s[j] - 'a'];
		if (v -> min_pos < j) 
			dp[i] = min(dp[i], dp[j - 1] + b);
	}
}		

int main(){
	cin >> n >> a >> b;
	cin >> s;
	s = ' ' + s;
	
	Node* trie = new Node;
	
	for (int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] + a;
		get(trie, s, i);
		insert(trie, s, i);
	}
	
	cout << dp[n] << "\n";
	return 0;
}
