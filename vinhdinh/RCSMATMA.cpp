#include <bits/stdc++.h>

using namespace std;

int const N = 22;
int const dx[] = {0, 0, 1, -1};
int const dy[] = {1, -1, 0, 0};

char arr[N][N];
int vis[N][N] = {};
int turn = 0;
int n, m;

int dequy(int i, int j){
	if (i < 1 || i > n || j < 1 || j > m) return 0;

	int ans = 0;
	for (int t = 0; t < 4; t++){
		int g = i + dx[t], h = j + dy[t];

		if (g < 1 || g > n || h < 1 || h > m) continue;
		if (vis[g][h] == turn) continue;
		if (arr[g][h] < arr[i][j]) continue;

		vis[g][h] = turn;
		ans = max(ans, dequy(g, h) + 1);
		vis[g][h] = 0;
	}
	return ans;
}

int main(){
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];

	int ans = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			turn++;
			int anss = dequy(i, j);
			ans = max(ans, anss + 1);
			// for (int y = 1; y <= n; y++)
			// 	for (int k = 1; k <= m; k++)
			// 		cout << vis[y][k] << " \n"[k == m];
			// cout << anss << "\n";
		}
	}

	cout << ans;
	return 0;
}