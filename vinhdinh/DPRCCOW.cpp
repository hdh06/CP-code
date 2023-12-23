#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int const N = 5001;

int n, m;
int a[N], b[N];

ll dp[N][N];

ll calc(int i, int j){
	if (i == n + 1) return 0;
	ll &ans = dp[i][j];
	if (ans != -1) return ans;
	ans = LLONG_MAX;
	ans = min(ans, calc(i + 1, j + 1) + abs(a[i] - b[j]));
	if (j < m - (n - i))
		ans = min(ans, calc(i, j + 1));
	return ans;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(1, 1);
	return 0;
}