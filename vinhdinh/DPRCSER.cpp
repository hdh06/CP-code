#include <bits/stdc++.h>

using namespace std;

int const L = 201, N = 501;

int l, n; 
int c[L][L];
int q[N];

int dp[N][L][L];

int calc(int i, int x, int y){
	if (i == n + 1) return 0;
	int z = q[i - 1];
	
	if (dp[i][x][y] != -1) return dp[i][x][y];
	
	if (x == q[i] || y == q[i] || z  == q[i]){
		int a, b;
		if (x == q[i]) a = z, b = y;
		if (y == q[i]) a = x, b = z;
		if (z == q[i]) a = x, b = y;
		return dp[i][x][y] = calc(i + 1, a, b);
	}
	
	int ans = INT_MAX;
	ans = min(ans, calc(i + 1, x, y) + c[z][q[i]]);
	ans = min(ans, calc(i + 1, z, y) + c[x][q[i]]);
	ans = min(ans, calc(i + 1, x, z) + c[y][q[i]]);
	return dp[i][x][y] = ans;
}

void solve(){
	cin >> l >> n;
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= l; j++){
			cin >> c[i][j];
		}
		
	for (int i = 1; i <= n; i++)
		cin >> q[i];
	q[0] = 3;
		
	memset(dp, -1, sizeof dp);
	
	cout << calc(1, 1, 2) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}