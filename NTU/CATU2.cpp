#include <bits/stdc++.h>

//CAY KHE 2 VINHDINH

using namespace std;

int const N = 1e3 + 1;

int main(){
	int n, m;
	cin >> n >> m;

	int v[N], w[N];
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

	int dp[N][N] = {};
 	bool track[N][N] = {};

	int maxn = 0, maxp = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			dp[j][i] = dp[j - 1][i];
			if (i - w[j] >= 0 && dp[j][i] < dp[j - 1][i - w[j]] + v[j]) {
				dp[j][i] = dp[j - 1][i - w[j]] + v[j];
				track[j][i] = 1;
			}
		}
		if (maxn <= dp[n][i]){
			maxn = dp[n][i];
			maxp = i;
		}
	}

	vector<int> path;
	for (int j = n, i = maxp;i > 0 && j > 0;j--){
		if (track[j][i]){
			path.push_back(j);
			i -= w[j];
		}
	}

	reverse(path.begin(), path.end());
	cout << maxn << endl;
	for (auto x: path) cout << x << " ";

	
	return 0;
}
    