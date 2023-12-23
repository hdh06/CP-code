#include <bits/stdc++.h>

using namespace std;

int const N = 501;

int y[N][N], b[N][N];
int dp[N][N] = {}, ty[N][N] = {}, tb[N][N] = {};

void solve(int n, int m){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
		 	cin >> y[i][j];
		 	ty[i][j] = ty[i][j - 1] + y[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> b[i][j];
			tb[i][j] = tb[i - 1][j] + b[i][j];
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i][j - 1] + tb[i][j], dp[i - 1][j] + ty[i][j]);

	cout << dp[n][m] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	while (n + m != 0){
		solve(n, m);
		cin >> n >> m;
	}	
	return 0;
}

// fun fact: ACM central europe