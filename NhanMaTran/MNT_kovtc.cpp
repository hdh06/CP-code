int const MOD = 1e9 + 7;

struct matrix{
	int n, m;
	int v[101][101];

	matrix(int _n, int _m, int init = 0){
		n = _n, m = _m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				v[i][j] = init;
	}

	matrix(){}
};

matrix idf(int sz){
	matrix c(sz, sz);
	for (int i = 0; i < sz; i++)
		c.v[i][i] = 1;
	return c;
}

matrix operator *(const matrix &a, const matrix &b){
	matrix c(a.n, b.m);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)
			for (int k = 0; k < a.m; k++)
				(c.v[i][j] += (1LL * a.v[i][k] * b.v[k][j] + MOD) % MOD) %= MOD;
 	return c;
}

matrix operator ^(const matrix &a, int n){
	if (n == 0) return idf(a.size());
	matrix ans = a ^ (n / 2);
	if (n & 1) return ans * ans * a;
	return ans * ans;
}

void print(const matrix &a){
	int w = 3;
	vector<int> maxw(a.m, 0);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.m; j++){
			string s = to_string(a[i][j]);
			maxw[j] = max(maxw[j], (int)s.size());
		}

	for (auto x: maxw) w += x + 1;
	
	cout << "+-";
	for (int i = 1; i <= w - 4; i++) cout << ' ';
	cout << "-+\n";

	for (int i = 0; i < a.n; i++){
		cout << "| ";
		for (int j = 0; j < a[i].m; j++){
			string s = to_string(a[i][j]);
			cout << s;
			for (int k = 1; k <= maxw[j] - s.size() + 1; k++) cout << ' ';
		}
		cout << "|\n";
	}

	cout << "+-";
	for (int i = 1; i <= w - 4; i++) cout << ' ';
	cout << "-+\n";
}
