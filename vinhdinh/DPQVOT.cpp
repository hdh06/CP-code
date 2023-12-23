#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int main(){
	int n, k;
	cin >> n >> k;

	int a[N] = {-1000}, b[N];

	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}

	long long dp[N] = {};

	for (int i = 1; i <= n; i++){
		for (int j = i - 1; j >= 0; j--) if (a[i] - a[j] >= k){
			dp[i] = max(dp[i], dp[j] + b[i]);
		}
	}

	// for (int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}