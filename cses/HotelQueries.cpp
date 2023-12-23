#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int tree[N << 2];

int n;

void build(int arr[], int x = 1, int l = 1, int r = n){
	if (l == r){
		if (l <= n) tree[x] = arr[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(arr, 2 * x, l, mid);
	build(arr, 2 * x + 1, mid + 1, r);

	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}

int que(int k, int x = 1, int l = 1, int r = n){
	if (l == r){
		if (tree[x] >= k){
			tree[x] -= k;
			return l;
		}
		return 0;
	}
	
	int mid = (l + r) >> 1, ans = 0;
	if (tree[2 * x] >= k) ans = que(k, 2 * x, l, mid);
	else if (tree[2 * x + 1] >= k) ans = que(k, 2 * x + 1, mid + 1, r);
	
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);

	return ans;
}

int main(){
	int q; cin >> n >> q;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];	

	build(arr);

	while (q--){
		int x; cin >> x;
		cout << que(x) << " ";
	}
	return 0;
}