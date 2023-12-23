#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int n;
int arr[N];

int tree[N << 2];

void build(int arr[], int x = 1, int l = 1, int r = n){
	if (l == r){
		tree[x] = arr[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(arr, 2 * x, l, mid);
	build(arr, 2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}

void upd(int pos, int val, int x = 1, int l = 1, int r = n){
	if (pos < l || r < pos) return;
	if (l == r){
		tree[x] = val;
		return;
	}
	
	int mid = (l + r) >> 1;
	upd(pos, val, 2 * x, l, mid);
	upd(pos, val, 2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}
 
int get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return tree[x];
	
	int mid = (l + r) >> 1;
	return max(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
}
 
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	build(arr);
	return 0;
}