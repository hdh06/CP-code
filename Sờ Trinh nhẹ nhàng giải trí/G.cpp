#include <bits/stdc++.h>

using namespace std;

struct node{
	node* tree[256] = {};
	node* link = nullptr;
	bool end = false;
};

node* nn(){return new node;}

void insert(node* root, string s){
	node* v = root;
	for (int c: s){
		if (!v -> tree[c])
			v -> tree[c] = nn();
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

		for (int i = 0; i < 256; i++){
			if (v -> tree[i]){
				v -> tree[i] -> link = root;
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
}

bool solve(){
	int n, m; cin >> n >> m;

	if (n == 0) return false;
	
	cin.ignore();
	node* root = nn();

	for (int i = 1; i <= n; i++){
		string t; getline(cin, t);
		insert(root, t);
	}

	build(root);

	int ans = 0;
	while (m--){
		string s;
		getline(cin, s);

		node* v = root;
		for (char c: s){
			while (1){
				if (v -> tree[c]){
					v = v -> tree[c];
					break;
				}

				if (!v -> link) break;
				v = v -> link;
			}

			if (v -> end){ 
				ans++;
				v = root;
			}		
		}
	}

	cout << ans << "\n";
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (solve());
	return 0;
}