#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int dp[N][N][N] = {};
int x, y, z, i, j, k; 
string a, b, c;

void solve(){
	cin >> x >> y >> z;
	cin >> a >> b >> c;

	a = ' ' + a;
	b = ' ' + b;
	c = ' ' + c;

	for (i = 1; i <= x; ++i){
		for (j = 1; j <= y; ++j){
			for (k = 1; k <= z; ++k){
				if (a[i] == b[j] && b[j] == c[k]) 
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = max(
					max(dp[i - 1][j][k], dp[i][j - 1][k])
					, dp[i][j][k - 1]);
			}
		}
	}
	cout << dp[x][y][z] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)	solve();
	return 0;
}