#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9;

int main(){
	int n;
	cin >> n;

	vector<long long> arr(n + 1);

	for (int i = 1; i <= n; i++) cin >> arr[i];

	vector<long long> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = (arr[1] != 2)?1:0;
	dp[2] = (arr[2] != 2)?dp[1] + ((arr[2] != 1)?dp[0]:0):0; dp[2] %= MOD;
	for (int i = 3; i <= n; i++){
		if (arr[i] == 2){
			dp[i] = 0;
		}
		else if (arr[i] == 1){
			dp[i] = dp[i - 1];
		}
		else{
			dp[i] = dp[i - 1] + dp[i - 2] + ((arr[i - 3] != 1)?dp[i - 3]:0);
			dp[i] %= MOD;
		}
	}

	// for (int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];

	cout << (dp[n] + dp[n - 1] + ((arr[n - 2] != 1)?dp[n - 2]:0))%MOD;

	return 0;
}
    