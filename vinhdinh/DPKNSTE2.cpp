#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int const M = 1e4 + 1;

int dp[M] = {};

vector<ii> s;

int main(){
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		int w, v, c; cin >> w >> v >> c;
		int p = 1;
		while (c - p > 0){
			s.push_back({w*p, v*p});
			c -= p;
			p <<= 1;
		}
		if (c > 0) s.push_back({w*c, v*c});
	}

	for (auto p: s){
		int w = p[0], v = p[1];
		for (int j = m; j >= w; j--){
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << *max_element(dp, dp + m + 1);
	return 0;
}