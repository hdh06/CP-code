#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
ll const INF = LLONG_MAX;
struct node{
	ll s = -INF, z = 0;
}tree[N << 2];
int n, arr[N];

void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		if (l <= n) tree[x].s = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	tree[x].s = max(tree[2 * x].s, tree[2 * x + 1].s);
}

void down(int x){
	ll k = tree[x].z;

	tree[2 * x].s += k;
	tree[2 * x].z += k;

	tree[2 * x + 1].s += k;
	tree[2 * x + 1].z += k;	

	tree[x].z = 0;
}

void upd(int L, int R, int k, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		tree[x].s += k;
		tree[x].z += k;
		return;
	}
	int mid = (l + r) >> 1;
	down(x);
	upd(L, R, k, 2 * x, l, mid);
	upd(L, R, k, 2 * x + 1, mid + 1, r);
	tree[x].s = max(tree[2 * x].s, tree[2 * x + 1].s);
}

ll get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return -INF;
	if (L <= l && r <= R) return tree[x].s;
	int mid = (l + r) >> 1;
	down(x);
	return max(
		get(L, R, 2 * x, l, mid),
		get(L, R, 2 * x + 1, mid + 1, r)
	);
}

// void print(int x = 1, int l = 1, int r = n){
// 	if (l == r){
// 		cout << "[" << x << "][" << l << "]" << ":" << tree[x].s << " " << tree[x].z << "\n";
// 		return;
// 	}
// 	int mid = (l + r) >> 1;
// 	print(2 * x, l, mid);
// 	print(2 * x + 1, mid + 1, r);
// 	cout << "[" << x << "][" << l << "][" << r << "]" << ":" << tree[x].s << " " << tree[x].z << "\n";
// }

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build();

	int q; cin >> q;
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, y, val; cin >> x >> y >> val;
			upd(x, y, val);
			// cout << "########\n";
			// print();
		}
		if (t == 2){
			int l, r; cin >> l >> r;
			cout << get(l, r) << '\n';
		}
	}
	return 0;
}