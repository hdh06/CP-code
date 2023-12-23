#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const M = 10001;

int main(){
	int	n, m, k;
	cin >> n >> m >> k;

	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dp[N][M]; dp[0][0] = 1;

	for (int i = 1; i <= n; i++) dp[i][0] = 1;

	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (i - arr[j] >= 0) dp[j][i] = dp[j - 1][i] + dp[j - 1][i - arr[j]];
			else dp[j][i] = dp[j - 1][i];
		}
	}

	if (dp[n][m] >= k) cout << "ENOUGH";
	else cout << dp[n][m];
	return 0;
}