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

string div2(string s){
	int du = 0;
	string ans;
	for (int i = 0; i < s.size(); i++){
		du = du * 10 + (s[i] - '0');
		ans.push_back(du / 2 + '0');
		du = du % 2;
	}
	if (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
	return ans;
}

matrix operator ^(const matrix &a, string n){
	if (n == "0") return idf(a);
	matrix ans = a ^ div2(n);
	if (n.back() & 1) return ans * ans * a;
	return ans * ans;
}

int main(){
	string n; cin >> n;
	matrix A = {{1, 1}, {1, 0}};
	matrix f = {{1}, {0}};
	
	matrix B = idf(A);
	for (matrix tmp = A; n != "0"; n = div2(n), tmp = tmp * tmp){
		if (n.back() & 1) B = B * tmp;
	}
	
	f = B * f;

	cout << f[1][0];
	return 0;
}
