#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) cin >> b[i];

	vector<ll> dp(n + 1, 0);
	dp[1] = a[1];
	for (int i = 2; i <= n; i++){
		dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
	}

	cout << dp[n];
	return 0;
}