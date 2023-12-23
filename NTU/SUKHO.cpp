#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k; cin >> n >> m >> k;
	int arr[101];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	int dp[10001] = {};
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= arr[i]; j--)
			dp[j] += dp[j - arr[i]], dp[j] = min(dp[j], 100);
			
	if (dp[m] >= k) cout << "ENOUGH\n";
	else cout << dp[m] << "\n";
	return 0;
}