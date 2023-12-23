x#include <bits/stdc++.h>

using namespace std;

	struct Node{
		Node* tree[256];
		int end;
	};

	Node* newNode(){
		Node* n = new Node;
		for (int i = 0; i < 256; i++)
			n -> tree[i] = nullptr;
		n -> end = -1;
		return n;
	}

	void insert(Node* root, string s, int i){
		Node* v = root;
		for (int x: s){
			if (!v -> tree[x])
				v -> tree[x] = newNode();
			v = v -> tree[x];
		}
		v -> end = ;
	}

	bool find(Node* root, string s){
		Node* v = root;
		for (int x: s){
			if (!v -> tree[x])
				return false;
			v = v -> tree[x];
		}
		return v -> end;
	}

int main(){
	int n; cin >> n;

	Node* tree = newNode();

	for (int i = 01)
		string t; cin >> t;
		insert(tree, t);
	}

	int q; cin >> q;

	while (q--){
		string s; cin >> s;
		cout << (find(tree, s)?"YES\n":"NO\n");
	}
	return 0;
}