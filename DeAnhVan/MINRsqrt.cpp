#include <bits/stdc++.h>

using namespace std;

int const INF = 1e9;
int const N = 1e5 + 5;
int const BLOCKS = 400;
int tree[BLOCKS + 1];
int arr[N];
int n, k;

int ID(int i){
	return ((i - 1) / 400) + 1;
}

void build(){
	for (int i = 1; i <= n; i++){
		tree[ID(i)] = min(tree[ID(i)],arr[i]);		
	}
}

int mintuche(int *x, int u, int v){
	if (u > v) return INF;
	int res = INF;

	for (int i = u; i <= v && i <= n; i++){
		res = min(res,x[i]);
	}

	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	memset(tree, 0x3f, sizeof tree);

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	build();

	for (int i = 1; i <= k; i++){
		int l , r;
		cin >> l >> r;

		int u = ID(l);
		int v = ID(r);

		if ((u - 1) * BLOCKS + 1 < l) u++;
		if (v * BLOCKS > r) v--;

		int res = mintuche(tree, u, v);
		res = min(res,mintuche(arr,l, min(r, (u - 1) * BLOCKS + 1)));
		res = min(res,mintuche(arr, max(l , v * BLOCKS + 1), r));
		cout << res << endl;
	}
	return 0;
}