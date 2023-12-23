#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const INF = 1e18;

struct node{
	ll pre, sum;
};

node merge(node A, node B){
	if (A.pre == -INF) return B;
	if (B.pre == -INF) return A;
	return {max(A.pre, A.sum + B.pre), A.sum + B.sum};
}

int const N = 2e5 + 1;
node tree[N << 2];

int n;

void build(int arr[], int x = 1, int l = 1, int r = n){
	if (r > n) return;
	if (l == r){
		tree[x].pre = arr[l];
		tree[x].sum = arr[l];
 		return;
	}

	int mid = (l + r) >> 1;
	build(arr, 2 * x, l, mid);
	build(arr, 2 * x + 1, mid + 1, r);

	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

void upd(int k, int val, int x = 1, int l = 1, int r = n){
	if (k < l || r < k) return;
	if (l == r){
		tree[x].pre = tree[x].sum = val;
		return;
	}

	int mid = (l + r) >> 1;
	upd(k, val, 2 * x, l, mid);
	upd(k, val, 2 * x + 1, mid + 1, r);

	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

node get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return {-INF, -INF};
	if (L <= l && r <= R)
		return tree[x];
	
	int mid = (l + r) >> 1;
	return merge(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
}

int main(){
	int q; cin >> n >> q;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build(arr);

	while (q--){
		int t; cin >> t;
		if (t == 1){
			int k, u; cin >> k >> u;
			upd(k, u);
		}else{
			int a, b; cin >> a >> b;
			cout << max(0ll, get(a, b).pre) << "\n";
		}
	}
	return 0;
}