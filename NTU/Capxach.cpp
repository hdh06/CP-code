#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	
	vector<long long> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= m; i++){
		int x; cin >> x;
		for (int j = x; j <= n; j++)
			dp[j] += dp[j - x];
	}
	cout << dp[n];
	return 0;
}