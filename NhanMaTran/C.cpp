#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const FMOD = 1e9 + 6;

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
				(c[i][j] += (1LL * a[i][k] * b[k][j] + FMOD) % FMOD) %= FMOD;
 	return c;
}

matrix operator ^(const matrix &a, int n){
	if (n == 0) return idf(a);
	matrix ans = a ^ (n / 2);
	if (n & 1) return ans * ans * a;
	return ans * ans;
}

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int main(){
	int a, b, k; cin >> a >> b >> k;
	matrix f = {{0}, {1}};
	matrix g = {{1}, {0}};
	matrix A = {{1, 1}, {1, 0}};

	if (k == 0){
		cout << a;
		return 0;
	}

	f = (A ^ (k - 1)) * f;
	g = (A ^ (k - 1)) * g;

	cout << 1LL * mpow(a, f[0][0]) * 1LL * mpow(b, g[0][0]) % MOD;
	// cout << 1LL * mpow(1000000000,1) * mpow(1000000000,1);
}