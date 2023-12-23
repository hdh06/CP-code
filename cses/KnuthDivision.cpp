#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const N = 5001;

typedef long long ll;
int main(){
	int n; cin >> n;
	ll sum[N] = {};
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		sum[i] = sum[i - 1] + x;
	}
	
	ll dp[N][N] = {};
	int opt[N][N] = {};
	for (int i = 1; i <= n; i++)
		opt[i][i] = i;
	
	auto C = [&](int i, int j){
		return sum[j] - sum[i - 1];
	};
	
	for (int i = n - 1; i >= 1; i--)
		for (int j = i + 1; j <= n; j++){
			dp[i][j] = LLONG_MAX;
			ll cost = C(i, j);
			for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++)
				if (dp[i][j] >= dp[i][k] + dp[k + 1][j] + cost)
					opt[i][j] = k, 
					dp[i][j] = dp[i][k] + dp[k + 1][j] + cost;
		}
	
	cout << dp[1][n];
	return 0;
}