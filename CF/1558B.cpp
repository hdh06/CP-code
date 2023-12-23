#include <bits/stdc++.h>

using namespace std;

int const N = 4e6 + 1;

int main(){
	int n, m; cin >> n >> m;	
	int dp[N] = {};
	dp[1] = 1;
	for (int i = 2; i <= n; i++){
		(dp[i] += (dp[i - 1] + 1) % m) %= m; 
		if (i != 2) (dp[i] += dp[i - 1]) %= m;
		for (int j = 2 * i; j <= n; j += i)
			(dp[j] += (dp[i] - dp[i - 1] + m) % m) %= m;
	}
	cout << dp[n] << "\n";
	return 0;
}