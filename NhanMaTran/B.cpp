#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

typedef vector<vector<int> > matrix;

matrix idf(matrix a){
	matrix c(a.size(), vector<int>(a.size(), 0));
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size(); j++)
			if (i - j == 0) c[i][j] = 1;
	return c;
}

matrix operator *(const matrix &a, const matrix &b){
	matrix c(a.size(), vector<int>(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			for (int k = 0; k < a[0].size(); k++)
				(c[i][j] += (1LL * a[i][k] * b[k][j] + MOD) % MOD) %= MOD;
 	return c;
}

matrix operator ^(const matrix &a, int n){
	if (n == 0) return idf(a);
	matrix ans = a ^ (n / 2);
	if (n & 1) return ans * ans * a;
	return ans * ans;
}

int main(){
	int n, k; cin >> n >> k;
	matrix A(n, vector<int>(n, 0));
	matrix f(n, vector<int>(1, 0));
	for (auto &x: f) cin >> x[0];
	reverse(f.begin(), f.end());
	for (auto &x: A[0]) cin >> x;

	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i - 1 - j == 0) A[i][j] = 1;

	if (k <= n - 1){
		cout << f[n - k - 1][0];
		return 0;
	}

	f = (A ^ max(0, k - n + 1)) * f;
	cout << f[0][0];
	return 0;
}