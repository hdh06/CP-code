#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 31;

int n;
int arr[N];

int pxor[N];

struct node{
	node* trie[2];
	int idx = -1;
};

void insert(node* root, int s, int k){
	node* v = root;
	for (int i = L - 1; i >= 0; i--){
		bool bit = !!(s & (1 << i));
		if (!v -> trie[bit])
			v -> trie[bit] = new node;
		v = v -> trie[bit];
	}
	v -> idx = k;
}

int find(node* root, int s){
	node* v = root;
	for (int i = L - 1; i >= 0; i--){
		bool bit = !!(s & (1 << i));
		if (v -> trie[!bit])
			v = v -> trie[!bit];
		else if (v -> trie[bit])
			v = v -> trie[bit];
		else return -1;
	}
	return v -> idx;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) pxor[i] = pxor[i - 1] ^ arr[i];
	
	node* r = new node;
	
	insert(r, 0, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, pxor[i] ^ pxor[find(r, pxor[i])]);
		insert(r, pxor[i], i);
	}
	
	cout << ans;
	return 0;
}