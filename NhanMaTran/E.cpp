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

	n += 1;

	matrix A(n + 2, vector<int> (n + 2, 0));
	A[0][0] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n + 2; j++)
			if (j == 0) A[i][j] = 1;
			else A[i][j] = (A[i - 1][j - 1] + A[i - 1][j]) % MOD;
	for (int j = 0; j < n; j++) cin >> A[n][j];
	A[n][n] = A[n][n + 1] = A[n + 1][n] = 1;

	if (k <= 1){
		cout << "0";
		return 0;
	}

	matrix f(n + 2, vector<int>(1, 0));
	f[0][0] = 1;
	for (int i = 1; i < n; i++) f[i][0] = f[i - 1][0] * 2 % MOD;

	f = (A ^ (k - 1)) * f;
	cout << f[n][0];
	return 0;
}