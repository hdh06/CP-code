#include <bits/stdc++.h>

using namespace std;

struct node{
	int val, pri, sz;
	bool rev;
	node *l, *r;
	node(){}
	node(int val): val(val), pri(rand()), sz(1), rev(0), l(NULL), r(NULL) {}
};
typedef node* pnode;

int sz(pnode v){
	return v? v -> sz: 0;
}
void upd_sz(pnode v){
	if (v)
		v -> sz = 1 + sz(v -> l) + sz(v -> r);
}
void push(pnode v){
	if (v && v -> rev){
		v -> rev = false;
		
		swap(v -> l, v -> r);
		if (v -> l) v -> l -> rev ^= 1;
		if (v -> r) v -> r -> rev ^= 1;
	}
}

void merge(pnode &v, pnode L, pnode R){
	push(L); push(R);
	if (!L || !R)
		v = L ? L : R;
	else
		if (L -> pri > R -> pri)
			merge(L -> r, L -> r, R), v = L;
		else 
			merge(R -> l, L, R -> l), v = R;
	upd_sz(v);
}

void split(pnode v, pnode &L, pnode &R, int key){
	push(v);
	if (!v) L = R = NULL;
	else
		if (key <= sz(v -> l))
			split(v -> l, L, v -> l, key), R = v;
		else
			split(v -> r, v -> r, R, key - sz(v -> l) - 1), L = v;
	upd_sz(v);
}

void reverse(pnode v, int l, int r){
	pnode t1, t2, t3;
	split(v, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	
	t2 -> rev ^= 1;
	
	merge(t2, t2, t3);
	merge(v, t1, t2);
}

void get(pnode v){
	push(v);
	if (!v) return;
	get(v -> l);
	cout << (char)(v -> val);
	get(v -> r);
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n, m; cin >> n >> m;
	string s; cin >> s;
	s = ' ' + s;
	
	pnode treap = NULL;
	for (int i = 1; i <= n; i++){
		pnode tmp = new node(s[i]);
		merge(treap, treap, tmp);
	}
	
	while (m--){
		int l, r; cin >> l >> r;
		reverse(treap, l, r);
	}
	
	get(treap);
	return 0;
}