#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	vector<int> dp(n + 1);
	for (int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + abs(arr[i] - arr[i - 1]);
		if (i - 2 > 0) dp[i] = min(dp[i], dp[i - 2] + abs(arr[i] - arr[i - 2]));
	}	
	cout << dp[n];
	return 0;
}