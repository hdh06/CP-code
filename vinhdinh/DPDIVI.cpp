#include <bits/stdc++.h>

using namespace std;

int const N = 6001;

int main(){
	int n, L;
	cin >> n >> L;

	int dp[N] = {}, arr[N] = {};

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++){
		dp[i] = max(dp[i - 1], L - arr[i]);
		for (int j = i - 1, tong = arr[i]; j >= 1; j--){
			tong += arr[j];
			if (tong > L) break;

			dp[i] = min(dp[i], max(dp[j - 1], L - tong));
		}
		// cout << dp[i] << " ";
	}

	cout << dp[n];
	return 0;
}