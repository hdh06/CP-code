#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	vector<int> dp(n, INT_MAX);
	
	dp[0] = 0;
	for (int i = 1; i < n; i++)
		for (int j = i - 1; j >= max(i - k, 0); j--)
			dp[i] = min(dp[i], dp[j] + abs(arr[j] - arr[i]));
		
	cout << dp[n - 1];
	return 0;
}