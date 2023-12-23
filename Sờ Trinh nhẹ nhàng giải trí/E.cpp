#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[128] = {};
	node* link = nullptr;

	int match = -1;
};

node* nn(){return new node;}

void insert(node* root, string s){
	node* v = root;
	for (int x: s){
		if (!v -> tree[x])
			v -> tree[x] = nn();
		v = v -> tree[x];
	}
}

void build(node* root){
	queue<node*> que;
	que.push(root);

	while (!que.empty()){
		node* v = que.front();
		que.pop();

		for (int i = 'a'; i <= 'z'; i++){
			if (v -> tree[i]){
				que.push(v -> tree[i]);
				v -> tree[i] -> link = root;
				node* p = v -> link;
				while (p){
					if (p -> tree[i]){
						v -> tree[i] -> link = p -> tree[i];
						break;
					}

					if (!p -> link) break;
					p = p -> link;
				}
			}
		}
	}
}

void mark(node* x, int i){
	if (!x) return;
	if (x -> match != -1) return;

	x -> match = i;
	mark(x -> link, i);
}

int main(){
	string s; cin >> s;
	int n; cin >> n;
	vector<string> t(n);

	node* root = nn();

	for (auto &x: t){
		cin >> x;
		insert(root, x);
	}

	build(root);

	node* v = root;
	for (int i = 0, c = s[0]; i < s.size(); i++, c = s[i]){
		while (1){
			if (v -> tree[c]){
				v = v -> tree[c];
				break;
			}

			if (!v -> link) break;
			v = v -> link;
		}
		mark(v, i);
	}

	for (auto x: t){
		node* v = root;
		for (int c: x)
			v = v -> tree[c];
		
		if (v -> match == -1) cout << "-1\n";
		else cout << v -> match - x.size() + 1 + 1 << "\n";
	}
	return 0;
}