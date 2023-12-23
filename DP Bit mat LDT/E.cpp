#include <bits/stdc++.h>

using namespace std;

int const N = 20;

int n;
int C[N][N];

int dp[N][1 << N];

int emrua(int i, int mask){
	if (i == n) return 0;
	if (dp[i][mask] != -1) return dp[i][mask]; 
	int ans = 0;
	for (int j = 0; j < n; j++) if (!(mask & (1 << j) ) )
		ans = max(ans, emrua(i + 1, mask | (1 << j)) + C[i][j]);
	return dp[i][mask] = ans;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> C[i][j];

	memset(dp, -1, sizeof dp);

	cout << emrua(0, 0);
	return 0;
}