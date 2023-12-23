#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 5;
ll const INF = LLONG_MIN;
ll dp[N], arr[N];

int main(){
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = LLONG_MIN;
		for (int j = i - 1; j >= i - k && j >= 0 && dp[j] != INF ; j--){
			dp[i] = max(dp[j] + arr[i], dp[i]);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
	return 0;
}