#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e7;

int const N = 501;

// 3(011) 5(101) 6(110) 7(111)

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	int arr[N][N];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
		
	int dp[N][N][8] = {};

	dp[1][1][0] = 1;
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (i == 1 && j == 1) continue;
			if (arr[i][j] == -1) continue;

			for (int k = 0; k < 8; k++){
				int shift = (arr[i][j] != 0 ? k|(1 << (arr[i][j] - 1)):k);
				dp[i][j][shift] += dp[i - 1][j][k] + dp[i][j - 1][k];
				dp[i][j][shift] %= MOD;
			}
		}
	}
	cout << (dp[n][m][3] + dp[n][m][5] + dp[n][m][6] + dp[n][m][7])%MOD;
	return 0;
}