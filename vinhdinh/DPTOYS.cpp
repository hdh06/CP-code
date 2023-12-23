#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 10;

int main(){
	int t; cin >> t;
	while(t--){
		int n;	
		cin >> n;

		ll arr[N];

		ll sum[N] = {};

		ll dp[N] = {};

		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
			// cout << sum[i] << " \n"[i == n];
		}

		int mod = 3;
		n += mod;

		// for (int i = 1; i <= n; i++) dp[i] = 0;

		for (int i = 1; i <= n; i++) if (i % 2 == 0){
			if (i >= 2) dp[i] = max(dp[i], dp[i - 2] + sum[i - 1] - sum[i - 2]);
			if (i >= 4) dp[i] = max(dp[i], dp[i - 4] + sum[i - 2] - sum[i - 4]);
			if (i >= 6) dp[i] = max(dp[i], dp[i - 6] + sum[i - 3] - sum[i - 6]);
		}

		// for (int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];

		n -= mod;
		cout << max({dp[n],
					dp[n + 1], 
					dp[n + 2],
					dp[n + 3],
					// dp[n - 1] + sum[n] - sum[n - 1],
					// dp[n - 2] + sum[n] - sum[n - 2],
					// dp[n - 3] + sum[n] - sum[n - 3],
					});
		cout << endl;
	}
	return 0;
}