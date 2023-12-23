#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const A = 1e9 + 7, B = 1e9 + 9;
int const N = 3e5 + 1;

int p[N];

void init(){
	p[0] = 1;
	for (int i = 1; i < N; i++)
		p[i] = 1LL * p[i - 1] * A % B;
}

struct node{
	int val, pri, sz;
	int hv, rhv;
	node *l, *r;
	node(){}
	node(int val): val(val), pri(rand()), sz(1), hv(val), rhv(val), l(NULL), r(NULL){}
};

typedef node* pnode;

int sz(pnode v){return v? v -> sz: 0;}
int hv(pnode v){return v? v -> hv: 0;}
int rhv(pnode v){return v? v -> rhv: 0;}
void upd(pnode v){
	if (v) {
		v -> sz = 1 + sz(v -> l) + sz(v -> r);
		v -> hv = ((1LL * hv(v -> l) * p[sz(v -> r) + 1] % B + 1LL * v -> val * p[sz(v -> r)] % B) % B + hv(v -> r)) % B;
		v -> rhv =((rhv(v -> l) + 1LL * v -> val * p[sz(v -> l)] % B) % B + 1LL * rhv(v -> r) * p[sz(v -> l) + 1] % B) % B; 
	}
}

void split(pnode v, pnode &L, pnode &R, int key){
	if (!v)
		L = R = NULL;
	else
		if (key <= sz(v -> l))
			split(v -> l, L, v -> l, key), R = v;
		else
			split(v -> r, v -> r, R, key - sz(v -> l) - 1), L = v;
	upd(v);
}

void merge(pnode &v, pnode L, pnode R){
	if (!L || !R)
		v = L? L: R;
	else 
		if (L -> pri > R -> pri)
			merge(L -> r, L -> r, R), v = L;
		else
			merge(R -> l, L, R -> l), v = R;
	upd(v);
}

int main(){
	init();
	int n, q; cin >> n >> q;
	
	pnode t = NULL; // implicit treap
	for (int i = 1; i <= n; i++){
		char c; cin >> c;
		pnode tmp = new node(c);
		merge(t, t, tmp);
	}
	
	while (q--){
		int c; cin >> c;
		if (c == 1){
			int l, r; cin >> l >> r;
			pnode t1, t2, t3;
			split(t, t1, t2, l - 1);
			split(t2, t2, t3, r - l + 1);
			
			merge(t, t1, t3);
		}
		if (c == 2){
			char x; int p; cin >> x >> p;
			pnode t1, t2;
			split(t, t1, t2, p - 1);
			
			pnode tmp = new node(x);
			merge(t, t1, tmp);
			merge(t, t, t2);
		}
		if (c == 3){
			int l, r; cin >> l >> r;
			pnode t1, t2, t3;
			split(t, t1, t2, l - 1);
			split(t2, t2, t3, r - l + 1);
			
			cout << (hv(t2) == rhv(t2)? "yes\n": "no\n");
			
			merge(t, t1, t2);
			merge(t, t, t3);
		}
	}
	return 0;
}