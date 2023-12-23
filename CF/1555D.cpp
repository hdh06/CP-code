#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int main(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	s = ' ' + s;
	vector<string> t = {"abc", "acb", "bac", "bca", "cab", "cba"};

	int psum[N][6] = {};
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 6; j++){
			psum[i][j] = psum[i - 1][j];
			if (s[i] != t[j][(i - 1) % 3]) psum[i][j] ++;		
		}
	}

	while (m--){
		int a, b; cin >> a >> b;
		int ans = INT_MAX;
		for (int i = 0; i < 6; i++)
			ans = min(ans, psum[b][i] - psum[a - 1][i]);
		cout << ans << "\n";
	}
	return 0;
}