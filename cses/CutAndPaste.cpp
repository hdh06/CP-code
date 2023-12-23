#include <bits/stdc++.h>

using namespace std;

struct node{
	int val, pri, sz;
	node *l, *r;
	node(){}
	node(int val):val(val), pri(rand()), sz(1), l(NULL), r(NULL){}
};

typedef node* pnode;

int sz(pnode v){
	return v? v -> sz: 0;
}
void upd_sz(pnode v){
	if (v)
		v -> sz = 1 + sz(v -> l) + sz(v -> r);
}

void split(pnode v, int key, pnode &L, pnode &R){
	if (!v) L = R = NULL;
	else
		if (key <= sz(v -> l))
			split(v -> l, key, L, v -> l), R = v;
		else
			split(v -> r, key - sz(v -> l) - 1, v -> r, R), L = v;
	upd_sz(v);
}
void merge(pnode &v, pnode L, pnode R){
	if (!L || !R)
		v = L ? L : R;
	else
		if (L -> pri > R -> pri)
			merge(L -> r, L -> r, R), v = L;
		else
			merge(R -> l, L, R -> l), v = R;
	upd_sz(v);
}

int const N = 2e5 + 1;
int p[N];
void get(pnode v, int curr = 0){
	if (!v) return;
	int vcurr = curr + sz(v -> l) + 1;
	p[vcurr] = v -> val;
	get(v -> l, curr);
	get(v -> r, curr + sz(v -> l) + 1);
}

int main(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	
	pnode treap = NULL;
	
	for (int i = 1; i <= n; i++){
		pnode tmp = new node(i);
		merge(treap, treap, tmp);	
	}
	
	while (m--){
		int l, r; cin >> l >> r;
		pnode t1, t2, t3;
		split(treap, l - 1, t1, t2);
		split(t2, r - l + 1, t2, t3);
		
		merge(t2, t3, t2);
		merge(treap, t1, t2);
	}
	get(treap);
	for (int i = 1; i <= n; i++){
		cout << s[p[i] - 1];
	}
	return 0;
}