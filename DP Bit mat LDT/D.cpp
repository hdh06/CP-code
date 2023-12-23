#include <bits/stdc++.h>

using namespace std;

int const N = 16;

int n;
int C[N][N];

int dp[1 << N][N];

int emrua(int mask, int last){
	if (mask == (1 << n) - 1)
		return 0;
	if (dp[mask][last] != -1) return dp[mask][last];
	int ans = 1000000;
	for (int i = 0; i < n; i++) if (!(mask & (1 << i)))
		ans = min(ans, emrua(mask | (1 << i), i) + C[last][i]);
	return dp[mask][last] = ans;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> C[i][j];

	memset(dp, -1, sizeof dp);

	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
		ans = min(ans, emrua(1 << i, i));
	cout << ans;
	return 0;
}