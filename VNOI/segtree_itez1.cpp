#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int tree[N << 2], n, arr[N];

void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		if (l <= n) tree[x] = arr[l];
		return;
	}

	int mid = (l + r) >> 1;

	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}

void upd(int p, int k, int x = 1, int l = 1, int r = n){
	if (p < l || p > r) return;

	if (l == r){
		tree[x] = k;
		return;
	}

	int mid = (l + r) >> 1;

	upd(p, k, 2 * x, l, mid);
	upd(p, k, 2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}

int get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return INT_MIN;

	if (L <= l && r <= R) return tree[x];
	
	int mid = (l + r) >> 1;

	return max(
		get(L, R, 2 * x, l, mid),
		get(L, R, 2 * x + 1, mid + 1, r)
	);
}

int main(){
	cin >> n;	
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build();

	int q; cin >> q;
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, y; cin >> x >> y;
			upd(x, y);
		}
		if (t == 2){
			int l, r; cin >> l >> r;
			cout << get(l, r) << '\n';
		}
	}
	return 0;
}