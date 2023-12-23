#include <bits/stdc++.h>

using namespace std;

int const N = 501;
int const M = 1e4 + 1;

int dp[M] = {};

int main(){
	int t;
	cin >> t;
	while(t--){
		int E, F;
		cin >> E >> F;
		int m = F - E, n;
		cin >> n;

		int v[N], w[N];
		for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

		for (int i = 1; i <= m; i++) dp[i] = INT_MAX;
		dp[0] = 0;
		int ans = 0;
		for (int j = 1; j <= m; j++){
			for (int i = 1; i <= n; i++){
				if (j - w[i] >= 0 && dp[j - w[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
			}
		}

		cout << (dp[m] == INT_MAX ? -1: dp[m]) << endl;
	}
	return 0;
}