#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	int val, pri, sz;
	bool rev;
	ll sum;
	node *l, *r;
	node(){}
	node(int val) : val(val), pri(rand()), sz(1), rev(0), sum(val), l(NULL), r(NULL) {}
};
typedef node* pnode;

int sz(pnode v){return v? v -> sz: 0;}
ll sum(pnode v){return v? v -> sum: 0;}
void upd_sz(pnode v){if (v) v -> sz = 1 + sz(v -> l) + sz(v -> r);}
void upd_sum(pnode v){if (v) v -> sum = sum(v -> l) + v -> val + sum(v -> r);}

void push(pnode v){
	if (v && v -> rev){
		v -> rev = false;
		swap(v -> l, v -> r);
		if (v -> l) v -> l -> rev ^= 1;
		if (v -> r) v -> r -> rev ^= 1;
	}
}

void split(pnode v, pnode &L, pnode &R, int key){
	push(v);
	if (!v) L = R = NULL;
	else 
		if (key <= sz(v -> l))
			split(v -> l, L, v -> l, key), R = v;
		else 
			split(v -> r, v -> r, R, key - sz(v -> l) - 1), L = v;
	upd_sum(L); upd_sum(R); upd_sz(v);
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
	upd_sum(v); upd_sz(v);
}

// void unlazy(pnode v){
	// push(v);
	// if (!v) return;
	// unlazy(v -> l);
	// cerr << v -> val << " ";
	// unlazy(v -> r);
// }

void reverse(pnode v, int l, int r){
	pnode t1, t2, t3;
	split(v, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	
	t2 -> rev ^= 1;
	
	merge(t2, t2, t3);
	merge(v, t1, t2);
}

ll sum(pnode v, int l, int r){
	pnode t1, t2, t3;
	split(v, t1, t2, l - 1);
	split(t2, t2, t3, r - l + 1);
	
	ll ans = sum(t2);
	merge(t1, t1, t2);
	merge(v, t1, t3);
	return ans;
}



int main(){
	int n, m; cin >> n >> m;
	pnode treap = NULL;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		pnode tmp = new node(x);
		merge(treap, treap, tmp);
	}
	
	while (m--){
		int t, l, r; cin >> t >> l >> r;
		if (t == 1)
			reverse(treap, l, r);
		if (t == 2)
			cout << sum(treap, l, r) << "\n";
	}
	return 0;
	
	
}