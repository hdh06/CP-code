#include <bits/stdc++.h>

using namespace std;

int const INF = 2e5;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> arr(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		
		
		vector<int> dp(n + 1, 0), pre(n + 1, -INF);
		for (int i = 1; i <= n; i++){
			dp[i] = dp[i - 1];
			if (pre[arr[i]] != -INF) dp[i] = max(dp[i], pre[arr[i]] + i + 1);
			pre[arr[i]] = max(pre[arr[i]], dp[i - 1] - i);
		}
		
		cout << dp[n] << "\n";
	}
	return 0;
}