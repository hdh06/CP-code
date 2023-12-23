#include <bits/stdc++.h>

using namespace std;

int const N = 5001;
typedef long long ll;

int n, m, k;
ll sum[N][N];

ll get(int x, int y, int u, int v){
	return sum[u][v] - sum[x - 1][v] - sum[u][y - 1] + sum[x - 1][y - 1];
}

int xuly(int x, int y){
	int ans = 0;
	for (int i = 0, j = 0; x + j <= n && y + j <= m && i <= j;){
		if (get(x + i, y + i, x + j, y + j) <= k) 
			ans = max(ans, j - i + 1), ++j;
		else ++i;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			scanf("%ll", sum[i][j]);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, xuly(i, 1));
	for (int i = 2; i <= m; ++i) ans = max(ans, xuly(1, i));	
	cout << ans;
	return 0;
}