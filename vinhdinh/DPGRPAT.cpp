#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const MOD = 1e9;

int main(){
	int n, m; cin >> n >> m;
	int arr[N][N] = {};

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];

	int dp[N][N] = {};	

	for (int i = 1; i <= n; i++) dp[i][1] = 1;

	for (int j = 1; j <= m; j++){
		for (int i = 1; i <= n; i++){
			for (int q = 1; q <= i; q++)
				for (int p = 1; p <= j; p++)
					if (p != m && i + j != p + q && gcd(arr[i][j], arr[q][p]) > 1)
						(dp[i][j] += dp[q][p]) %= MOD;
		}
	}

 	// for (int i = 1; i <= n; i++)
 	// 	for (int j = 1; j <= m; j++) cout << dp[i][j] << " \n"[j == m];

	int tong = 0;
	for (int i = 1; i <= n; i++)
		(tong += dp[i][m]) %= MOD;

	cout << tong;
	return 0;
}