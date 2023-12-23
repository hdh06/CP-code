#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int nd = 4;
int dx[] = {1, -1, -2, +2};
int dy[] = {-2, -2, -1, -1};

int main(){
	int n; cin >> n;
	int fob[N];
	for (int i = 1; i <= n; i++)
		cin >> fob[i];

	int dp[N][(1 << 4) - 1][(1 << 4) - 1] = {};
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int m1 = 0; m1 < (1 << 4); m1++)
			for (int m2 = 0; m2 < (1 << 4); m2++)
				for (int m3 = 0; m3 < (1 << 4); m3++){
					if ((m1 | m2 | m3) & 1) continue;
					if (m3 & (1 << fob[i])) continue;
				
					bool flag = 1;
					for (int j = 1; j < 4; j++) if (m3 & (1 << j)){
						for (int t = 0; t < nd; t++){
							int x = j + dx[t];
							int y = i + dy[t];
							if (x < 1 || 3 < x) continue;
							if (y <= 0) continue;
							if (y == i - 1 && (m2 & (1 << x))) flag = 0;
							if (y == i - 2 && (m1 & (1 << x))) flag = 0;
						}
					}
					if (!flag) continue;

					int cnt = 0;
					for (int j = 1; j < 4; j++) if (m3 & (1 << j))
						cnt++;
					dp[i][m2][m3] = max(dp[i][m2][m3], dp[i - 1][m1][m2] + cnt);
					// if (i == 2 && m2 == (1 << 3) + (1 << 1) && m1 == 0 && m3 == 0) cout << dp[i - 1][m1][m2] << "\n";
					// cout << i << " " << bitset<4>(m1) << " " << bitset<4>(m2) << " " << bitset<4>(m3) << "\n";
					ans = max(ans, dp[i][m2][m3]);
				}
	// cout << dp[1][0][(1 << 3) + (1 << 1)] << "\n";
	cout << ans;	
	return 0;
}