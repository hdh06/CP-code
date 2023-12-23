#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1001;
int const MOD = 1000000007;

ll dp[N][3];

int main(){
	int n;

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	cin >> n;

	for (int i = 2; i <= n; i++){
		dp[i][0] = dp[i - 1][1] + dp[i - 1][2]; dp[i - 1][0] %= MOD;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];	dp[i - 1][1] %= MOD;
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]; dp[i - 1][1] %= MOD;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2])%MOD;

	return 0;
}
    