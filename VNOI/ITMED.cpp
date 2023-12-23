#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

typedef long long ll;

ll tree[N << 2];

int n;

void upd(int k, ll val, int x = 1, int l = 1, int r = n){
	if (k < l || k > r) return;
	if (l == r){
		tree[x] = val;
		return;
	}

	int mid = (l + r) >> 1;

	upd(k, val, 2 * x, l, mid);
	upd(k, val, 2 * x + 1, mid + 1, r);

	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}

ll get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return LLONG_MIN;
	if (L <= l && r <= R) return tree[x];

	int mid = (l + r) >> 1;
	return max(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
}

signed main(){
	int k; cin >> n >> k;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];
		
	upd(1, arr[1]);

	for (int i = 2; i <= n; i++){
		upd(i, max(0LL, get(max(1, i - k), i - 1)) + arr[i]);
	}

	cout << max(0LL, get(1, n));
	return 0;
}