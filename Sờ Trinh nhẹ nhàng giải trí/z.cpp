#include <bits/stdc++.h>

using namespace std;

struct node{
	map<int, node*> tree;
	node* link = nullptr;
	bool end = false;
	bool calc = false;
	bool match = false;
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

		for (int i = 0; i < 256; i++) if (v -> tree[i]){
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


int num(char c){return c - '0';};
char chr(int c){return c + '0';};

string cong(string a, string b){
	if (a.size() > b.size()) swap(a, b);
	while (a.size() < b.size()) a = '0' + a;

	int du = 0;
	string c;
	for (int i = a.size() - 1; i >= 0; i--){
		du += num(a[i]) + num(b[i]);
		c = chr(du % 10) + c;
		du /= 10;
	}
	if (du > 0) c = chr(du) + c;
	return c;
}

int n, m, p;
string s;

node* root = nn();

string emrua(int i, node* cur){
	if (i == m)
		return "1";
	string ans = "0";
	for (int x: s){
		node* u = cur;
		while (!u -> tree[x] && u -> link)
			u = u -> link;
		if (u -> tree[x] && u -> tree[x] -> end)
			continue;
		ans = cong(ans, emrua(i + 1,(u -> tree[x]? u -> tree[x]: root)));
	}
	return ans;
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