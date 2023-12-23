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

void print(matrix a){
	int w = 3;
	vector<int> maxw(a[0].size(), 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++){
			string s = to_string(a[i][j]);
			maxw[j] = max(maxw[j], (int)s.size());
		}

	for (auto x: maxw) w += x + 1;
	
	cout << "+-";
	for (int i = 1; i <= w - 4; i++) cout << ' ';
	cout << "-+\n";

	for (int i = 0; i < a.size(); i++){
		cout << "| ";
		for (int j = 0; j < a[i].size(); j++){
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
