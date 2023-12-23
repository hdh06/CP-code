#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll const INF = LLONG_MAX;

typedef vector<vector<ll> > matrix;

matrix idf(int sz){
	matrix c(sz, vector<ll>(sz, INF));
	for (int i = 0; i < sz; i++)
		c[i][i] = 0;
	return c;
}

matrix operator *(const matrix &a, const matrix &b){
	matrix c(a.size(), vector<ll>(b[0].size(), INF));
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			for (int k = 0; k < a[0].size(); k++) if (INF - a[i][k] > b[k][j])
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
 	return c;
}

matrix operator ^(const matrix &a, int n){
	if (n == 0) return idf(a.size());
	matrix ans = a ^ (n / 2);
	if (n & 1) return ans * ans * a;
	return ans * ans;
}

int main(){
	int n, m, k; cin >> n >> m >> k;
	matrix A(n + 1, vector<ll>(n + 1, INF));
	matrix f(n + 1, vector<ll>(1, INF));		

	f[1][0] = 0;

	while (m--){
		ll a, b, w; cin >> a >> b >> w;
		A[b][a] = min(A[b][a], w);
	}

	f = (A ^ k) * f;
	cout << (f[n][0] == INF? -1: f[n][0]);
	return 0;
}