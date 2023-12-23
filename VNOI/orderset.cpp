#include <bits/stdc++.h>

using namespace std;

struct node{
	int val, pri, sz = 0;
	node *l, *r;
	node() {}
	node(int val): val(val), pri(rand()), sz(1), l(NULL), r(NULL) {}
	
};

typedef node* pnode;

int sz(pnode v){
	return v? v -> sz: 0;
}
void upd_sz(pnode &v){
	if (v){
		v -> sz = 1 + sz(v -> l) + sz(v -> r);
	}
}

void split(pnode v, int key, pnode &L, pnode &R){
	if (!v) L = R = NULL;
	else
		if (key > v -> val)
			split(v -> r, key, v -> r, R), L = v;
		else 
			split(v -> l, key, L, v -> l), R = v;
	upd_sz(v);
}
void merge(pnode &v, pnode L, pnode R){
	if (!L || !R)
		v = L ? L: R;
	else
		if (L -> pri > R -> pri)
			merge(L -> r, L -> r, R), v = L;
		else
			merge(R -> l, L, R -> l), v = R;
	upd_sz(v);
}
void insert(pnode &v, pnode key){
	if (!v)
		v = key;
	else
		if (key -> pri > v -> pri)
			split(v, key -> val, key -> l, key -> r), v = key;
		else insert(key -> val <= v -> val? v -> l: v -> r, key);
	upd_sz(v);
}
void erase(pnode &v, int key){
	if (!v) return;
	if (v -> val == key){
		auto tmp = v;
		merge(v, v -> l, v -> r);
		delete tmp;
	}else
		erase(key <= v -> val? v -> l: v -> r, key);
	upd_sz(v);
}
bool search(pnode v, int key){
	if (!v) return 0;
	if (v -> val == key) return 1;
	return search(key < v -> val? v -> l: v -> r, key);
}

int cnt(pnode v, int key){
	if (!v) return 0;
	if (v -> val == key) return sz(v -> l) + 1;
	if (key < v -> val) return cnt(v -> l, key);
	return sz(v -> l) + 1 + cnt(v -> r, key);	
}
int const INF = INT_MAX;
int ksearch(pnode v, int k){
	if (!v) return -INF;
	if (k == sz(v -> l) + 1) return v -> val;
	if (k < sz(v -> l) + 1)
		return ksearch(v -> l, k);	
	else 
		return ksearch(v -> r, k - sz(v -> l) - 1);
}

int main(){
	int q; cin >> q;
	pnode treap = NULL;
	while (q--){
		char c; int k; cin >> c >> k;
		if (c == 'I'){
			if (!search(treap, k)){
				pnode tmp = new node(k);
				insert(treap, tmp);
			}
		}
		if (c == 'D'){
			if (search(treap, k))
				erase(treap, k);
		}
		if (c == 'C')
			cout << cnt(treap, k - 1) << "\n";
		if (c == 'K'){
			int tmp = ksearch(treap, k);
			if (tmp == -INF)
				cout << "invalid\n";
			else cout << tmp << "\n";
		}
	}
	return 0;
}