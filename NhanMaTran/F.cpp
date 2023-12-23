#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

typedef vector<vector<int> > matrix;

matrix idf(int sz){
	matrix c(sz, vector<int>(sz, 0));
	for (int i = 0; i < sz; i++)
		c[i][i] = 1;
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
	if (n == 0) return idf(a.size());
	matrix ans = a ^ (n / 2);
	if (n & 1) return ans * ans * a;
	return ans * ans;
}

int main(){
	matrix A = {{1, 1, -1}, {1, 0, 0}, {0, 0, 1}};
	matrix f = {{0}, {0}, {1}};

	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	k++;

	matrix C = idf(3);
	for (auto x: arr){
		A[0][2] = x;
		C = A * C;
	} 

	matrix D = idf(3);
	for (int i = 0; i < k % n; i++){
		A[0][2] = arr[i];
		D = A * D;
	}

	f = D * (C ^ (k / n)) * f;
	cout << f[0][0];
	return 0;
}