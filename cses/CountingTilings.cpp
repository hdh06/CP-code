#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int const N = 10;

int dp[2][1 << N];

int main(){
	int n, m; cin >> n >> m;

	dp[0][0] = 1;
	for (int j = 1; j <= m; j++)
	for (int i = 0; i < n; i++){
		for (int mask = 0; mask < (1 << n); mask++){
				dp[1][mask] = dp[0][mask ^ (1 << i)];
				if (i && !(mask & (1 << i)) && !(mask & (1 << (i - 1))))
					(dp[1][mask ]+= dp[0][mask ^ (1 << (i - 1))]) %= MOD;
			}
		swap(dp[0], dp[1]);
	}
			
	cout << dp[0][0];
	return 0;
}
