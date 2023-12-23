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
				(c[i][j] += 1LL * a[i][k] * b[k][j] % MOD) %= MOD;
 	return c;
}

matrix operator ^(const matrix &a, int n){
	if (n == 0) return idf(a);
	matrix ans = a ^ (n / 2);
	if (n & 1) return ans * ans * a;
	return ans * ans;
}

int main(){
	int n; cin >> n;
	matrix A = {{1, 1}, {1, 0}};
	matrix f = {{1}, {1}};

	f = (A ^ max(0 ,n - 1)) * f;

	cout << f[0][0];
	return 0;
}