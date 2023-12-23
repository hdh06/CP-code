#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const INF = 1e18;

typedef vector<vector<ll> > matrix;

matrix idf(int sz){
	matrix c(sz, vector<ll>(sz, -INF));
	for (int i = 0; i < sz; i++)
		c[i][i] = 0;
	return c;
}

matrix operator *(const matrix &a, const matrix &b){
	matrix c(a.size(), vector<ll>(b[0].size(), -INF));
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			for (int k = 0; k < a[0].size(); k++)
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
 	return c;
}

matrix operator ^(const matrix &a, int n){
	if (n == 0) return idf(a.size());
	matrix ans = a ^ (n / 2);
	if (n & 1) return ans * ans * a;
	return ans * ans;
}
int main(){
	int a, b, k; cin >> a >> b >> k;
	matrix A = {{a, b}, {0, -INF}};
	matrix f = {{0}, {0}};

	f = (A ^ max(0, k - 1)) * f;

	cout << f[0][0];
	return 0;
}