#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 101;
int const V = 1e3*N;
ll const INF = 1e9*N;

ll dp[N][V] = {};
int n, m;
ll s = 0;
int w[N], v[N];

int main(){
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];
		s += v[i];
	}

	int maxn = 0;
	for (int i = 1; i <= s; i++){
		dp[0][i] = INF;
		for (int j = 1; j <= n; j++) {
			dp[j][i] = dp[j - 1][i]; 
			if (i - v[j] >= 0) dp[j][i] = min(dp[j][i], dp[j - 1][i - v[j]] + w[j]);
			// cout << dp[j][i] << " \n"[j == n];
		}
		if (dp[n][i] <= m){
			maxn = max(maxn, i);
		}
	}

	cout << maxn;
	return 0;
}