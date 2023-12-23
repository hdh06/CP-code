#include <bits/stdc++.h>

using namespace std;

int const N = 2023;
int const W = 2022;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;

		int w[N];

		for (int i = 2; i <= n + 1; i++) cin >> w[i];

		int dp[N][W] = {};

		for (int j = 1; j <= x; j++){
			for (int i = 2; i <= n + 1; i++){
				dp[i][j] = dp[i - 1][j];
				if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 2][j - w[i]] + w[i]);
				// cout << dp[i][j] << " \n"[i == n + 1];
			}
		}	

		cout << dp[n + 1][x] << " ";
	}
	return 0;
}