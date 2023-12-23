#include <bits/stdc++.h>

using namespace std;

int const N = 3;
int const MOD = 1e9 + 7;

struct matrix{
	int n, m;
	int v[N][N] = {};
	matrix(){}
	matrix(int n, int m) :n(n), m(m) {}
};

matrix operator * (matrix const &a, matrix const &b){
	assert(a.n == b.m);
	matrix c(b.n, a.m);
	
	for (int i = 1; i <= b.n; i++)
		for (int j = 1; j <= a.m; j++)
			for (int k = 1; k <= a.n; k++)
				(c.v[i][j] += 1LL * a.v[k][i] * b.v[j][k] % MOD) %= MOD;
	return c;
}

matrix idf(int n){
	matrix c(n, n);
	for (int i = 1; i <= n; i++) c.v[i][i] = 1;
	return c;
}

matrix operator ^ (matrix const &a, int n){
	assert(a.n == a.m);
	if (n == 0) return idf(a.n);
	matrix c = a ^ (n / 2);
	if (n & 1) return c * c * a;
	return c * c;
}

int main(){
	int n; cin >> n;
	
	matrix f(2, 1);
	f.v[1][1] = f.v[2][1] = 1;
	/*
		f(i)
		f(i - 1)
	*/
	
	matrix A(2, 2);
	A.v[1][1] = A.v[1][2] = A.v[2][1] = 1;
	/*
		1 1
		1 0
	*/
	
	f = f * (A ^ (n - 1));
	/*
		->
		f(i + n - 1)
		f(i + n - 2)
	*/
	
	cout << f.v[1][1];
	
	return 0;
}