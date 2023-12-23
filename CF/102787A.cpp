#include <bits/stdc++.h>

using namespace std;

struct node{
	int val, pri, sz;
	node *l, *r;
	node(){}
	node(int val): val(val), pri(rand()), sz(0), l(NULL), r(NULL){}
};
typedef node* pnode;
int sz(pnode v){return v? v -> sz: 0;}
void upd_sz(pnode v){if (v) v -> sz = 1 + sz(v -> l) + sz(v -> r);}

void split(pnode v, pnode &L, pnode &R, int key){
	if (!v)
		L = R = NULL;
	else
		if (key <= sz(v -> l))
			split(v -> l, L, v -> l, key), R = v;
		else
			split(v -> r, v -> r, R, key - sz(v -> l) - 1), L = v;
	upd_sz(v);
}

void merge(pnode &v, pnode L, pnode R){
	if (!L || !R)
		v = L? L: R;
	else
		if (L -> pri > R -> pri)
			merge(L -> r, L -> r, R), v = L;
		else
			merge(R -> l, L, R -> l), v = R;
	upd_sz(v);
}

void get(pnode v){
	if (!v) return;
	get(v -> l);
	cout << v -> val << " ";
	get(v -> r);
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;
	
	pnode treap = NULL;
	for (int i = 1; i <= n; i++){
		pnode tmp = new node(i);
		merge(treap, treap, tmp);
	}
	
	for (int i = 1; i <= n; i++){
		int a, b; cin >> a >> b;
		if (a >= b) continue;
		pnode t1, t2, t3, t4, t5;
		split(treap, t1, t2, a - 1);
		split(t2, t2, t3, min(b - a, n - b + 1));
		split(t3, t3, t4, max(0, b - a - (n - b + 1)));
		split(t4, t4, t5, min(b - a, n - b + 1));
		
		merge(treap, t1, t4);
		merge(treap, treap, t3);
		merge(treap, treap, t2);
		merge(treap, treap, t5);
	}
	
	get(treap);
	return 0;
}