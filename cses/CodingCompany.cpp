#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const X = 5001;
int const MOD = 1e9 + 7;

int n, x;
int t[N];

int dp[N][N][X + X];

int calc(int i, int j, int p){
	if (p > x) return 0;
	if (i == n + 1) return (j == 0);
	
	int &ans = dp[i][j][p + X];
	if (ans != -1) return ans;
	ans = 0;

	(ans += calc(i + 1, j, p)) %= MOD;
	if (j) (ans += 1LL * j * calc(i + 1, j, p) % MOD) %= MOD;
	if (j) (ans += 1LL * j * calc(i + 1, j - 1, p + t[i]) % MOD) %= MOD;
	(ans += calc(i + 1, j + 1, p - t[i])) %= MOD;

	return ans;
}

int main(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
		
	sort(t + 1, t + n + 1);
	
	memset(dp, -1, sizeof dp);
	cout << calc(1, 0, 0);
	return 0;
}