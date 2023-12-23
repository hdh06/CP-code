#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const INF = 2e18;
int const N = 101;

struct matrix{
	int n, m;
	ll v[N][N];

	matrix(int _n, int _m, ll init = 0){
		n = _n, m = _m;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				v[i][j] = init;
	}

	matrix() {

	}
};

matrix idf(int sz){
	matrix c(sz, sz, INF);
	for (int i = 0; i < sz; i++)
		c.v[i][i] = 0;
	return c;
}

matrix operator *(matrix a, matrix b){
	matrix c(a.n, b.m, INF);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)
			for (int k = 0; k < a.m; k++)// if (INF - a.v[i][k] > b.v[k][j])
				c.v[i][j] = min(c.v[i][j], a.v[i][k] + b.v[k][j]);
 	return c;
}

matrix p2[64];
void init(matrix a){
	p2[0] = a;
	for (int i = 1; i < 64; i++){
		p2[i] = p2[i - 1] * p2[i - 1];
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; ll W;
	cin >> n >> m >> W;

	matrix A(n + 1, n + 1, INF);
	matrix f(n + 1, 1);
	f.v[0][0] = INF;

	for (int i = 1; i <= n; i++) A.v[0][i] = 0;

	while (m--){
		ll a, b, w; cin >> a >> b >> w;
		A.v[b][a] = min(A.v[b][a], w);
	}

	init(A);

	ll ans = 0;

	for (ll l = 0, r = W; l <= r;){
		ll mid = (l + r) >> 1;

		matrix g = f;
		for (int i = 0; i < 64; i++)
			if ((mid + 1) & (1LL << i))
				g = p2[i] * g;
		ll z = g.v[0][0];
		if (z <= W){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}

	cout << ans;
	return 0;
}