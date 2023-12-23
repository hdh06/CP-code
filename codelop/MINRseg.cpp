#include <bits/stdc++.h> 

using namespace std;

int const INF = 1e9;
int const N = 1e5 + 5;
int seg[N << 2];
int arr[N];

void build(int node, int l, int r){
	if (l == r){
		seg[node] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	int left = node * 2;
	int right = node * 2 + 1;
	build(left, l, mid);
	build(right, mid + 1, r);
	seg[node] = min(seg[left],seg[right]);
}

void update(int node, int l, int r, int p, int x){
	if (p < l || p > r) return;
	if (p == l && p == r){
		seg[node] = x;
		return;
	}
	int mid = (l + r) / 2;
	int left = node * 2;
	int right = node * 2 + 1;
	update(left, l, mid, p, x);
	update(right, mid + 1, r, p, x);
	seg[node] = min(seg[left],seg[right]);
}

int mintuche(int node, int l, int r, int u, int v){
	if (r < u || v < l) return INF;
	if (u <= l && r <= v) return seg[node];
	int mid = (l + r) / 2;
	int left = node * 2;
	int right = node * 2 + 1;
	int kql = mintuche(left, l, mid, u, v);
	int kqr = mintuche(right, mid + 1, r, u, v);
	return min(kql, kqr);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		cin >> arr[i];
	}
	build(1,1,n);
	while(k--){
		int l , r;
		cin >> l >> r;
		cout << mintuche(1,1,n,l,r) << endl;
	}
	return 0;
}