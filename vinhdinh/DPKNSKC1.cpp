#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1001;
int const M = 11112;

ll dp[M] = {};
ll arr[N], v[N] = {};

int main(){
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> v[i] >> arr[i];

	dp[0] = 0;
	ll maxn = 0;
	for (int j = 1; j <= m; j++){
		for (int i = 1; i <= n; i++) if (j - arr[i] >= 0){
			dp[j] = max(dp[j], dp[j - arr[i]] + v[i]);
		}
		maxn = max(maxn, dp[j]);
	}

	cout << maxn;
	return 0;
}