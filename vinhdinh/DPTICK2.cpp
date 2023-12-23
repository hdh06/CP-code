#include <bits/stdc++.h>

using namespace std;

int const N = 60001;

int main(){
	int n;
	cin >> n;
	int s[N], d[N];

	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 2; i <= n; i++) cin >> d[i];

	int dp[N];
	dp[1] = s[1];
	dp[2] = min(s[1] + s[2], d[2]);

	for (int i = 3; i <= n; i++){
		dp[i] = min(dp[i - 2] + d[i], dp[i - 1] + s[i]);
	}


	// for (int i = 1; i <= n; i++){
	// 	cout << dp[i] << " \n"[i == n];
	// }
	vector<int> ans;

	while (n >= 3){
		if (dp[n] == dp[n - 1] + s[n]){
			ans.push_back(n);
			n--;
		}
		else if (dp[n] == dp[n - 2] + d[n]){
			ans.push_back(n - 1);
			n -= 2;
		}
	}

	if (n > 0){
		if (n == 2 && dp[2] == s[1] + s[2]) ans.push_back(2);
		ans.push_back(1);
	}

	cout << ans.size() << endl;

	reverse(ans.begin(), ans.end());

	for (auto x: ans) cout << x << " ";
	return 0;
}