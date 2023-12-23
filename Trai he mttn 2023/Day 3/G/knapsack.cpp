#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int main(){
	int n, m; cin >> n >> m;

	int dp[N] = {};
	for (int i = 1; i <= n; i++){
		int w, v; cin >> w >> v;
		for (int j = m; j >= 0; j--)
			dp[j] = max(dp[j], dp[j - w] + v);
	}

	cout << *max_element(dp, dp + m);
	return 0;
}
