#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int main(){
	int n, q; cin >> n >> q;
	int dp[N][N] = {};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			char t; cin >> t;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (t == '*');
		}

	while (q--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << "\n";
	}
	return 0;
}