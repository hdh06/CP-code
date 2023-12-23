#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
ll tree[N << 2];
int n;

void upd(int p, int k, int x = 1, int l = 1, int r = n){
	if (p < l || r < p) return;
	if (l == r){
		tree[x] = k;
		return;
	}

	int mid = (l + r) >> 1;
	upd(p, k, 2 * x, l, mid);
	upd(p, k, 2 * x + 1, mid + 1, r);

	tree[x] = tree[2 * x] + tree[2 * x + 1];
}

ll get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return tree[x];

	int mid = (l + r) >> 1;
	return get(L, R, 2 * x, l, mid) + get(L, R, 2 * x + 1, mid + 1, r);
}

int main(){
	cin >> n;
	int q; cin >> q;
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, y; cin >> x >> y;
			upd(x, y);
		}
		if (t == 2){
			int l, r; cin >> l >> r;
			cout << get(l, r) << "\n";
		}
	}
	return 0;
}