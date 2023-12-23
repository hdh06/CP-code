#include <bits/stdc++.h>

using namespace std;

struct node{
	int val, pri, sz;
	node *l, *r;
	bool rev, ror;
	
	int ans, pre, suf;
	int tpre, tsuf;
	
	int sum;
	node(){}
	node(int val) :val(val), pri(rand()), sz(1), l(NULL), r(NULL), rev(0), ror(0), ans(1), pre(1), suf(1), tpre(val), tsuf(val), sum(val) {}
};
typedef node* pnode;
	
int sz(pnode v){return v? v -> sz: 0;}
int ans(pnode v){return v? v -> ans: 0;}
int pre(pnode v){return v? v -> pre: 0;}
int suf(pnode v){return v? v -> suf: 0;}
int tpre(pnode v){return v? v -> tpre: 2;}
int tsuf(pnode v){return v? v -> tsuf: 2;}
int sum(pnode v){return v? v -> sum: 0;}

	
void push(pnode v){
	if (v){
		if (v -> rev){
			v -> rev = false;
			swap(v -> l, v -> r);
			swap(v -> pre, v -> suf);
			swap(v -> tpre, v -> tsuf);
			if (v -> l) v -> l -> rev ^= 1;
			if (v -> r) v -> r -> rev ^= 1;
		}
		if (v -> ror){
			v -> ror = false;
			v -> val ^= 1;
			v -> tpre ^= 1, v -> tsuf ^= 1;
			v -> sum = v -> sz - v -> sum;
			if (v -> l) v -> l -> ror ^= 1;
			if (v -> r) v -> r -> ror ^= 1;
		}
	}
}

void upd(pnode v){
	if (v){
		v -> sz = 1 + sz(v -> l) + sz(v -> r);
		v -> pre = pre(v -> l) 
				+ (pre(v -> l) == sz(v -> l)? 
					(!sz(v -> l) || tpre(v -> l) == v -> val? 1 
						+ (tpre(v -> r) == v -> val? pre(v -> r): 0)
				  :0)
				:0);
		v -> suf = suf(v -> r) 
				+ (suf(v -> r) == sz(v -> r)? 
					(!sz(v -> r) || tsuf(v -> r) == v -> val? 1 
						+ (tsuf(v -> l) == v -> val? suf(v -> l): 0)
				  :0)
				:0);
		v -> tpre = sz(v -> l)? tpre(v -> l): v -> val;
		v -> tsuf = sz(v -> r)? tsuf(v -> r): v -> val;
		
		v -> ans = max({1, v -> pre, v -> suf, 
						suf(v -> l) + (!sz(v -> l) || tsuf(v -> l) == v -> val), 
						pre(v -> r) + (!sz(v -> r) || tpre(v -> r) == v -> val),
						(!sz(v -> l) || tsuf(v -> l) == v -> val) && (!sz(v -> r) || tpre(v -> r) == v -> val)? suf(v -> l) + 1 + pre(v -> r): 0
						});
						
		v -> sum = v -> val + sum(v -> l) + sum(v -> r);
	}
}

void split(pnode v, pnode &L, pnode &R, int key){
	push(v);
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
	push(L), push(R);
	if (!L || !R)
		v = L ? L : R;
	else
		if (L -> pri > R -> pri)
			merge(L -> r, L -> r, R), v = L;
		else
			merge(R -> l, L, R -> l), v = R;
	upd(v);
}

void print(pnode v){
	push(v);
	if (!v) return;
	print(v -> l);
	cerr << v -> val << " ";
	print(v -> r);
	upd(v);
}

int main(){
	int n, q; cin >> n >> q;
	
	pnode t = NULL;
	for (int i = 1; i <= n; i++){
		char c; cin >> c; c -= '0';
		pnode tmp = new node(c);
		merge(t, t, tmp);
	}		
	
	pnode A = NULL, B = NULL;
	for (int i = 1; i <= n; i++){
		pnode a = new node(0), b = new node(1);
		merge(A, A, a);
		merge(B, B, b);
	}
	
	while (q--){
		int type, l, r; cin >> type >> l >> r;
		if (type == 1){
			pnode t1, t2, t3;
			split(t, t1, t2, l - 1);
			split(t2, t2, t3, r - l + 1);
			
			t2 -> ror ^= 1;
			
			merge(t, t1, t2);
			merge(t, t, t3);
		}
		if (type == 2){
			pnode t1, t2, t3;
			split(t, t1, t2, l - 1);
			split(t2, t2, t3, r - l + 1);
			
			t2 -> rev ^= 1;
			
			merge(t, t1, t2);
			merge(t, t, t3);
		}
		if (type == 3){
			pnode t1, t2, t3;
			split(t, t1, t2, l - 1);
			split(t2, t2, t3, r - l + 1);
			
			pnode tmp = NULL;
			pnode a1, a2, b1, b2;
			
			if (t2 -> sz == t2 -> sum){
				split(B, b1, b2, t2 -> sz - 1);
				tmp = b1;
				merge(B, b1, b2);
			}else if (t2 -> sz == 0){
				split(A, a1, a2, t2 -> sz - 1);
				tmp = a1;
				merge(A, a1, a2);
			}else{
				split(A, a1, a2, t2 -> sz - t2 -> sum - 1);
				split(B, b1, b2, t2 -> sum - 1);
				
				merge(tmp, a1, b1);
				
				print(A); cerr << "\n";
				
				merge(A, a1, a2);
				merge(B, b1, b2);	
			}

			merge(t, t1, tmp);
			merge(t, t, t3);
		}
		// print(t); cerr << "\n";
		cout << t -> ans << "\n";
	}
	return 0;
}