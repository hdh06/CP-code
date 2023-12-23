#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[128] = {};
	node* link = nullptr;

	bool match;
};

node* nn(){return new node;}

void insert(node* root, string s){
	node* v = root;
	for (int c: s){
		if (!v -> tree[c])
			v -> tree[c] = nn();
		v = v -> tree[c];
	}
}

void build(node* root){
	queue<node*> que;

	que.push(root);

	while (!que.empty()){
		node* v = que.front();
		que.pop();

		for (int i = 0; i < 128; i++)
			if (v -> tree[i]){
				v -> tree[i] -> link = root;
				node* p = v -> link;
				while (p){
					if (p -> tree[i]){
						v -> tree[i] -> link = p -> tree[i];
						break;
					}

					if (!p -> link)
						break;

					p = p -> link;
				}
				que.push(v -> tree[i]);
			}
	}
}

void mark(node* v){
	if (!v) return;
	if (v -> match) return;
	v -> match = true;
	mark(v -> link);
}

int main(){
	string s; cin >> s;
	int n; cin >> n;
	vector<string> t(n);

	node* tree = nn();

	for (auto &x: t){
		cin >> x;
		insert(tree, x);
	}

	build(tree);

	node* v = tree;
	for (int x: s){
		while (1){
			if (v -> tree[x]){
				v = v -> tree[x];
				break;
			}

			if (!v -> link) break;

			v = v -> link;
		}
		mark(v);
	}

	for (auto x: t){
		node* v = tree;
		for (int c: x) v = v -> tree[c];

		cout << (v -> match?"Y\n":"N\n");	
	}
	return 0;
}