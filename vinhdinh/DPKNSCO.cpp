#include <bits/stdc++.h>

using namespace std;

int const M = 1e3 + 1;

int main(){
	int t; cin >> t;
	while(t --){
		int n, m;
		cin >> m >> n;

		vector<int> c(n + 1);

		for (int i = 1; i <= n; i++) cin >> c[i];

		int dp[M] = {};

		for (int i = 1; i <= m; i++){
			dp[i] = INT_MAX;
			for (int j = 1; j <= n; j++) if (i - c[j] >= 0 && dp[i - c[j]] != INT_MAX){
				dp[i] = min(dp[i], dp[i - c[j]] + 1);
			}
		}	

		cout << (dp[m] == INT_MAX?-1:dp[m]) << endl;
	}
	return 0;
}