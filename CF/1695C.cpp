#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int arr[N][N];
int maxx[N][N], minn[N][N];

void solve(){
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			maxx[i][j] = max(maxx[i - 1][j], maxx[i][j - 1]) + arr[i][j],
			minn[i][j] = min(minn[i - 1][j], minn[i][j - 1]) + arr[i][j];

	if ((n + m - 1) % 2 != 0 || minn[n][m] > 0 || maxx[n][m] < 0)
		cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;

	memset(minn, 0x3f, sizeof minn);
	minn[0][1] = minn[1][0] = 0;
	memset(maxx, -0x3f, sizeof maxx);
	maxx[0][1] = maxx[1][0] = 0;

	while(t--) solve();
	return 0;
}