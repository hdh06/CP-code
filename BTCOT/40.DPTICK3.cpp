#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e4 + 1;
ll const INF = LLONG_MAX;

int main(){
	ll L1, L2, L3, C1, C2, C3;
	cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3;
	int n;
	cin >> n;
	int s, f;
	cin >> s >> f;
	ll arr[N], dp[N];

	for (int i = 2; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) dp[i] = INF;

	dp[s] = 0;
	for (int i = s; i <= f; i++){
		if (dp[i] == INF)continue;
		for (int j = i + 1; j <= n && arr[j] - arr[i] <= L1; j++){
			dp[j] = min(dp[j], dp[i] + C1);
		}
		for (int j = i + 1; j <= n && arr[j] - arr[i] <= L2; j++){
			dp[j] = min(dp[j], dp[i] + C2);
		}
		for (int j = i + 1; j <= n && arr[j] - arr[i] <= L3; j++){
			dp[j] = min(dp[j], dp[i] + C3);
		}
	}

	cout << dp[f];

	return 0;
}
    