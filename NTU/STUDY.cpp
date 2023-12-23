#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int main(){
	int n, m; cin >> n >> m;
	int c[N][N] = {};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
			
	int dp[N][N] = {};
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + c[i][k]);
			
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max(ans, dp[n][i]);
	
	cout << ans << "\n";
	int x = n, y = m;
	for (int i = 1; i <= m; i++) if (ans == dp[x][i]) y = i;
	
	vector<int> z;
	
	while (x){
		int t = 0;
		for (int i = 0; i <= y; i++) 
			if (dp[x - 1][y - i] + c[x][i] == dp[x][y])
				t = i;
		z.push_back(t);
		x--, y -= t;
	}
	reverse(z.begin(), z.end());
	for (auto x: z) cout << x << "\n";
	
	return 0;
}