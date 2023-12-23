#include <bits/stdc++.h>

using namespace std;

int const N = 201;

int dp[N][N][N] = {}, w[N], v[N]; 
int m1, m2, n;

int main(){
	cin >> m1 >> m2 >> n;

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int x = 0; x <= m1; x++){
			for (int y = 0; y <= m2; y++){
				dp[i][x][y] = dp[i - 1][x][y];
				if (x - w[i] >= 0) dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x - w[i]][y] + v[i]);
				if (y - w[i] >= 0) dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x][y - w[i]] + v[i]);
				ans = max(ans, dp[i][x][y]);
			}
		}
	}

	cout << ans;
	return 0;
}