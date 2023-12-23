#include <bits/stdc++.h>

using namespace std;

int const N = 301;

int arr[N][N] = {}, dp[N][N] = {};

int n, m;

int v(int i, int j){
	// if (i < 1 || i > n || j < 1 || j > m) return 0;
	if (arr[i][j] < 0) return -1;
	else return 1;
}

int main(){

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];


	for (int i = 1; i <= n; i++)
		dp[i][1] = arr[i][1];
	

	int maxn = INT_MIN;
	for (int j = 2; j <= m; j++){
		for (int i = 1; i <= n; i++){
			dp[i][j] =                              dp[i    ][j - 1] + arr[i][j];
			if (i - 1 >= 1) dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + arr[i][j]);
			if (i + 1 <= n) dp[i][j] = max(dp[i][j],dp[i + 1][j - 1] + arr[i][j]);			
		}
	}

	for (int i = 1; i <= n; i++) maxn = max(maxn, dp[i][m]);

	cout << maxn;

	return 0;
}