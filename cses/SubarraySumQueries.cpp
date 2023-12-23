#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	ll ans, pre, suf, sum;
};

int const N = 2e5 + 1;
node tree[N << 2];

int n;

node merge(node A, node B){
	node ans;
	ans.ans = max({A.ans, B.ans, A.suf + B.pre});
	ans.pre = max(A.pre, A.sum + B.pre);
	ans.suf = max(B.suf, B.sum + A.suf);
	ans.sum = A.sum + B.sum;
	return ans;
}

void setNode(node &x, int val){
	x.ans = val;
	x.pre = val;
	x.suf = val;
	x.sum = val;
}

void build(int arr[], int x = 1, int l = 1, int r = n){
	if (l == r){
		if (l <= n)
			setNode(tree[x], arr[l]);
		return;
	}

	int mid = (l + r) >> 1;
	build(arr, 2 * x, l, mid);
	build(arr, 2 * x + 1, mid + 1, r);

	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

ll get(){
	return tree[1].ans;
}

void upd(int k, int val, int x = 1, int l = 1, int r = n){
	if (k < l || r < k)
		return;
	if (l == r){
		setNode(tree[x], val);
		return;
	}

	int mid = (l + r) >> 1;
	upd(k, val, 2 * x, l, mid);
	upd(k, val, 2 * x + 1, mid + 1, r);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

int main(){
	cin >> n; int q; cin >> q;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build(arr);

	while (q--){
		int k, val; cin >> k >> val;
		upd(k, val);
		cout << max(0ll, get()) << "\n";
	}
	return 0;
}