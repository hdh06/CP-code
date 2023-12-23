#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	int dp[100][1 << 4][1 << 4] = {};
	for (int i = 0; i < (1 << 4); i++) dp[1][i][0] = 1;	
	for (int i = 2; i <= m; i++)
		for (int y = 0; y < (1 << n); y++)
		for (int j = 0; j < (1 << n); j++)
		for (int k = 0; k < (1 << n); k++){
			int c = 1;
			for (int x = 0; x < n; x++){
				if (y & (1 << x)){
					if (x - 1 >= 0 && k & (1 << (x - 1))) c = 0;
					if (x + 1 < n && k & (1 << (x + 1))) c = 0;
					if (x - 2 >= 0 && j & (1 << (x - 2))) c = 0;
					if (x + 2 < n && j & (1 << (x + 2))) c = 0;
				}
			}
			if (c) dp[i][y][j] += dp[i][j][k];
		}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < (1 << n); j++)
			ans += dp[m][i][j];
	cout << ans;
	return 0;
}