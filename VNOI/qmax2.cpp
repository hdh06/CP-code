#include <bits/stdc++.h>

using namespace std;

int const N = 5e4 + 1;
struct node{
	int s = 0, lz = 0;
};
node tree[N << 4];
int n;

void down(int x){
	int k = tree[x].lz;

	tree[2 * x].s += k;
	tree[2 * x].lz += k;

	tree[2 * x + 1].s += k;
	tree[2 * x + 1].lz += k;

	tree[x].lz = 0;
}

void upd(int L, int R, int k, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		tree[x].s += k;
 		tree[x].lz += k;
		return;
	}

	int mid = (l + r) >> 1;

	down(x);

	upd(L, R, k, 2 * x, l, mid);
	upd(L, R, k, 2 * x + 1, mid + 1, r);

	tree[x].s = max(tree[2 * x].s, tree[2 * x + 1].s);
}

int get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return INT_MIN;
	if (L <= l && r <= R) return tree[x].s;

	int mid = (l + r) >> 1;

	down(x);

	return max(
		get(L, R, 2 * x, l, mid),
		get(L, R, 2 * x + 1, mid + 1, r)
	);
}

int main(){
	cin >> n;
	int q; cin >> q;
	while (q--){
		int t; cin >> t;
		if (t == 0){
			int x, y, k; cin >> x >> y >> k;
			upd(x, y, k);
		}
		if (t == 1){
			int x, y; cin >> x >> y;
			cout << get(x, y) << "\n";
		}
	}
	return 0;
}