#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2*1e5 + 5;

ll seg[N << 2] = {};

ll arr[N];

int n, q;

void build(int x, int L, int R){
	if (L == R){
		if (1 <= L && L <= n) seg[x] = arr[L];
		else seg[x] = 0;
		return;
	}

	int mid = (L + R)/2;
	int xL = 2*x;
	int xR = 2*x + 1;

	build(xL, L, mid);
	build(xR, mid + 1, R);

	seg[x] = seg[xL] + seg[xR];
}

void update(int x, int L, int R, int p, int u){
	if (L == R && L == p){
		seg[x] = u;
		return;
	}

	int mid = (L + R)/2;
	int xL = 2*x;
	int xR = 2*x + 1;

	if (p <= mid) update(xL, L, mid, p, u);
	if (p > mid) update(xR, mid + 1, R, p, u);

	seg[x] = seg[xL] + seg[xR];
}

ll calc(int x, int L, int R, int l, int r){
	if (L == R || (l <= L && R <= r)){
		return seg[x];	
	}

	int mid = (L + R)/2;
	int xL = 2*x;
	int xR = 2*x + 1;

	ll tong = 0;
	if (l <= mid) tong += calc(xL, L, mid, l, r);
	if (r > mid) tong += calc(xR, mid + 1, R, l, r); 	
	return tong;
}

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build(1, 1, n);

	while(q --){
		int type;
		cin >> type;

		if (type == 1){
			int p, u;
			cin >> p >> u;
			update(1, 1, n, p, u);
		}
		else{
			int a, b;
			cin >> a >> b;
			cout << calc(1, 1, n, a, b) << endl;
		}

	}
	return 0;
}
