#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> dp(n);
	cin >> dp[0];
	int ans = 0;
	for (int i = 1; i < n; i++){
		int t; cin >> t;
		ans = max(ans, t - dp[i - 1]);
		dp[i] = min(dp[i - 1], t);
	}	

	cout << ans;
	return 0;
}