#include <bits/stdc++.h>

using namespace std;

#define MOD (long long)1e9+7

int main(){
	int n;
	cin >> n;
	long long dp[1000001] = {};
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 6 && i - j >= 0; j ++){
			dp[i] += dp[i - j];
		}
		dp[i] %= MOD;
	}
	cout << dp[n];
	return 0;
}