#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int const MOD = 1e9 + 7;

int main(){
	int dp[N] = {};
	dp[0] = 1;
	for (int i = 2; i < N; i++)
		for (int j = i; j < N; j++)
			(dp[j] += dp[j - i]) %= MOD;
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}

// 012345

// s[l:r + 1]
// s[l:] s[:r + 1]