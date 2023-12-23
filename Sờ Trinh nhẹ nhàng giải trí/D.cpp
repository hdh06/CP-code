#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[128] = {};
	// map<char, node*> tree; 
	node* link = nullptr;
	bool end = false;

	bool calc = false;
	bool match = false;
	int cnt = 0;
};

node* nn(){
	node* n = new node;
	return n;
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

vector<node*> od;
void build(node* root){
	queue<node*> que;
	que.push(root);
	while (!que.empty()){
		node* v = que.front();
		que.pop();

		od.push_back(v);

		for (int i = 'a'; i <= 'z'; i++) 
			if (v -> tree[i]){
				que.push(v -> tree[i]);
				v -> tree[i] -> link = root;
				node * p = v -> link;
				while (p){
					if (p -> tree[i]){
						v -> tree[i] -> link = p -> tree[i];
						break;
					}

					if (!p -> link)
						break;
					p = p -> link;
				}
			}
	}
}

void mark(node *v){
	if (!v) return;
	if (v -> calc) return;

	v -> match = 1;
	mark(v -> link);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;	
	int n; cin >> n;

	node* root = nn();

	vector<string> t(n);
	for (auto &x: t) {
		cin >> x;
		insert(root, x);
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
		v -> cnt++;
		mark(v);
	}	

	reverse(od.begin(), od.end());

	for (auto x: od){
		if (!x) continue;
		if (!x -> link) continue;
		x -> link -> cnt += x -> cnt;
	}

	for (auto x: t){
		node* v = root;
		for (int c: x)
			v = v -> tree[c];
		cout << v -> cnt << "\n";
	}
	return 0;
}