#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1231234
#endif

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

int n, q;

ll tree[N << 2], tree_sqr[N << 2], lz_inc[N << 2], lz_set[N << 2];
void down(int x, int l, int r){
	int mid = (l + r) >> 1;
	if (lz_set[x] != -1001){
		tree[2 * x] = lz_set[x] * (mid - l + 1);
		tree[2 * x + 1] = lz_set[x] * (r - mid);
		tree_sqr[2 * x] = lz_set[x] * lz_set[x] * (mid - l + 1);
		tree_sqr[2 * x + 1] = lz_set[x] * lz_set[x] * (r - mid);
		lz_set[2 * x] = lz_set[2 * x + 1] = lz_set[x];
		lz_inc[2 * x] = lz_inc[2 * x + 1] = 0;
		lz_set[x] = -1001;
	}
	tree_sqr[2 * x] += 2 * tree[2 * x] * lz_inc[x] + lz_inc[x] * lz_inc[x] * (mid - l + 1);
	tree_sqr[2 * x + 1] += 2 * tree[2 * x + 1] * lz_inc[x] + lz_inc[x] * lz_inc[x] * (r - mid);
	tree[2 * x] += lz_inc[x] * (mid - l + 1);
	tree[2 * x + 1] += lz_inc[x] * (r - mid);
	lz_inc[2 * x] += lz_inc[x];
	lz_inc[2 * x + 1] += lz_inc[x];
	lz_inc[x] = 0;
}

//1: inc, 2: set
void upd(int L, int R, ll val, int type, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		if (type == 1){
			lz_inc[x] += val;
			tree_sqr[x] += 2LL * tree[x] * val + val * val * (r - l + 1);
			tree[x] += val * (r - l + 1);
		}else{
			lz_inc[x] = 0;
			lz_set[x] = val;
			tree[x] = val * (r - l + 1);
			tree_sqr[x] = val * val * (r - l + 1);
		}
		return;
	}
	int mid = (l + r) >> 1;
	down(x, l, r);
	upd(L, R, val, type, 2 * x, l, mid);
	upd(L, R, val, type, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x] + tree[2 * x + 1];
	tree_sqr[x] = tree_sqr[2 * x] + tree_sqr[2 * x + 1];
}
ll get(int L, int R, int x = 1, int l = 1, int r = n){
	// debug(l, r, x, tree_sqr[x], lz_set[x], lz_inc[x]);
	if (r < L || R < l) return 0;
	if (L <= l && r <= R){
		// debug(L, R, l, r, tree_sqr[x], lz_set[x], lz_inc[x]);
		return tree_sqr[x];
	}
	int mid = (l + r) >> 1;
	down(x, l, r);
	return get(L, R, 2 * x, l, mid) + get(L, R, 2 * x + 1, mid + 1, r);
}

#define file "f"

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	for (int i = 0; i < N * 4; i++) lz_set[i] = -1001;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		upd(i, i, x, 2);
	}
	
	// debug(get(1, 5));
	
	while (q--){
		int type; cin >> type;
		if (type == 2){
			int l, r; cin >> l >> r;
			cout << get(l, r) << "\n";
		}
		if (type == 1){
			int l, r, v; cin >> l >> r >> v;
			upd(l, r, v, 1);
		}
		if (type == 0){
			int l, r, v; cin >> l >> r >> v;
			upd(l, r, v, 2);
		}
	}
	return 0;
}