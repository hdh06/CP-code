#include <bits/stdc++.h>

using namespace std;

int const N = 16;
int const INF = N * 10001;

int n;
int dp[N][1 << N], c[N][N];

int calc(int v, int mask){
	if (mask == (1 << n) - 1) return 0;
	int &ans = dp[v][mask];
	if (ans != -1) return ans;
	ans = INF;
	for (int u = 0; u < n; u++) if (! (mask & (1 << u)))
		ans = min(ans, calc(u, mask | (1 << u)) + c[v][u]);
	return ans;	
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
			
	memset(dp, -1, sizeof dp);
	int ans = INF;
	for (int i = 1; i <= n; i++)
		ans = min(ans, calc(i, 0));
	
	cout << ans;
	return 0;
}