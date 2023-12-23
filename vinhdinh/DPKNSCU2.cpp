#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const W = 501;

int main(){
	int m, n;
	int dp[W] = {}, w[N] = {}, v[N] = {};
	cin >> m >> n;
	while (m + n > 0){
		for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

		for (int i = 0; i <= m; i++) dp[i] = 0;

		for (int i = 1; i <= n; i++){
			for (int j = m; j >= 0; j--)
				if (j - w[i] >= 0) dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
		}
		
		int maxv = 0, minw = 0;
		for (int i = 0; i <= m; i++){
			if (dp[i] > maxv){
				maxv = dp[i];
				minw = i;
			}
		}

		cout << minw << " " << maxv << endl;

		cin >> m >> n;
	}	
	return 0;
}