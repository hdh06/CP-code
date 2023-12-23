#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const INF = 2e18;

struct matrix{
	int n, m;
	ll v[2][2] = {};

	matrix(int _n, int _m, ll init = 0){
		n = _n, m = _m;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				v[i][j] = init;
	}

	matrix(){}
};

matrix idf(int sz){
	matrix c(sz, sz, -INF);
	for (int i = 0; i < sz; i++)
		c.v[i][i] = 0;
	return c;
}

matrix operator *(const matrix &a, const matrix &b){
	assert(a.m == b.n);
	matrix c(a.n, b.m, -INF);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)
			for (int k = 0; k < a.m; k++)
				c.v[i][j] = max(c.v[i][j], a.v[i][k] + b.v[k][j]);
 	return c;
}

int const N = 1e5 + 1;
matrix tree[N << 2];
ll lz[N << 2];
int n;
void build(matrix C[], int x = 1, int l = 1, int r = n){
	if (l == r){
		if (l <= n) tree[x] = C[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(C, 2 * x, l, mid);
	build(C, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x + 1] * tree[2 * x];
}

void down(int x){
	ll &t = lz[x];
	int a = 2 * x, b = 2 * x + 1;
	tree[a].v[0][1] -= t;
	tree[a].v[1][0] += t;
	lz[a] += t;

	tree[b].v[0][1] -= t;
	tree[b].v[1][0] += t;
	lz[b] += t;
	t = 0;
}

void upd(int L, int R, int k, int x = 1,int l = 1, int r = n){
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		lz[x] += k;
		tree[x].v[0][1] -= k;
		tree[x].v[1][0] += k;
		return;
	}

	int mid = (l + r) >> 1;

	down(x);

	upd(L, R, k, 2 * x, l, mid);
	upd(L, R, k, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x + 1] * tree[2 * x];
}


matrix get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return idf(2);
	if (L <= l && r <= R) return tree[x];

	int mid = (l + r) >> 1;

	down(x);

	return get(L, R, 2 * x + 1, mid + 1, r) * get(L, R, 2 * x, l, mid);  
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q;
	matrix C[N];
	for (int i = 1; i <= n; i++){
		C[i].n = C[i].m = 2;
		cin >> C[i].v[1][0];
		C[i].v[0][1] = -C[i].v[1][0];
	}

	build(C);

	matrix f(2, 1);
	f.v[1][0] = -INF;

	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r, k; cin >> l >> r >> k;
			upd(l, r, k);
		}else{
			int l, r; cin >> l >> r;
			matrix ans = get(l, r) * f; 
			cout << max(ans.v[0][0], ans.v[1][0]) << "\n";
		}
	}
	return 0;
}//https://codeforces.com/contest/1420/problem/C2