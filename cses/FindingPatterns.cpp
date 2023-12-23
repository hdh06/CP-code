#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[128];
	node* link;
	bool end;

	bool calc;
	bool match;
};

node* nn(){
	node* n = new node;
	for (int i = 0; i < 128; i++)
		n -> tree[i] = 0;
	n -> end = n -> calc = n -> match = false;
	n -> link = nullptr;
	return n;
}

void build(node* root){
	queue<node*> que;
	que.push(root);

	while (!que.empty()){
		node* v = que.front();
		que.pop();
		for (int i = 'a'; i <= 'z'; i++){
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
}

void insert(node* root, string s){
	node* v = root;
	for (int x: s){
		if (!v -> tree[x])
			v -> tree[x] = nn();
		v = v -> tree[x];
	}
	v -> end = true;
}

void mark(node* v){
	if (!v) return;

	// if (v -> calc) return;

	v -> match = true;
	// v -> calc = true;
	mark(v -> link);
}

int main(){
	string s; cin >> s;

	int n; cin >> n;
	vector<string> t(n);
	node* root = nn();

	for (int i = 0; i < n; i++){
		cin >> t[i];
		insert(root, t[i]);
	}

	build(root);

	node* v = root;
	for (int x: s){
		while (1){
			if (v -> tree[x]){
				v = v -> tree[x];
				break;
			}

			if (!v -> link)
				break;

			v = v -> link;
		}
		mark(v);
	}

	for (auto x: t){
		v = root;
		for (int c: x)
			v = v -> tree[c];
		
		if (v -> match)
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}