#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[256] = {};
	node* link = nullptr;
	bool end = false;
	bool calc = false;
	bool match = false;
};

node* nn(){return new node;}

void insert(node* root, string s){
	node* v = root;
	for (int c: s){
		if (!v -> tree[c]){
			v -> tree[c] = nn();
			v -> tree[c] -> link = root;
		}
		v = v -> tree[c]; 
	}
	v -> end = true;
}

void build(node* root){
	queue<node*> que;
	que.push(root);

	while (!que.empty()){
		node* v = que.front();
		que.pop();

		for (int i = 0; i < 256; i++) if (v -> tree[i]){
			// v -> tree[i] -> link = root;
			node* p = v -> link;
			while (p){
				if (p -> tree[i]){
					v -> tree[i] -> link = p -> tree[i];
					v -> tree[i] -> end |= p -> tree[i] -> end;
					break;
				}

				if (!p -> link) break;
				p = p -> link;
			}
			que.push(v -> tree[i]);
		}
	}
}

int const MOD = 1e9 + 7;

int n, m, p;
string s;

node* root = nn();

string b;

map<pair<int, node*>, int> ma;

int emrua(int i, node* cur){
	if (i == m)
		return 1;
	if (ma.find({i, cur}) != ma.end()) return ma[{i, cur}];
	int ans = 0;
	for (int x: s){
		node* u = cur;
		while (!u -> tree[x] && u -> link)
			u = u -> link;
		if (u -> tree[x] && u -> tree[x] -> end)
			continue;
		(ans += emrua(i + 1,(u -> tree[x]? u -> tree[x]: root))) %= MOD;
	}
	return ma[{i, cur}] = ans;
}

int main(){
	cin >> n >> m >> p;	
	cin >> s;

	vector<string> t(p);
	for (auto &x: t) cin >> x;

	for (auto x: t) insert(root, x);
	build(root);
	
	cout << emrua(0, root) << "\n";
	return 0;
}