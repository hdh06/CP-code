#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int dy[] = {-2, -1,  1,  2, 2, 1, -1, -2};

bool vis[11][11] = {}, vis2[11][11];

ofstream fo("out.out");

int dequy(int x, int y, int n){
	if (x < 1|| 10 < x || y < 1 || 10 < y) return 0;

	if (n == 0){
		if (!vis2[x][y]){
			vis2[x][y] = true;
			return 1;
		}
		return 0;
	}

	int ans = 0;
	for (int t = 0; t < 8; t++) if(!vis[x + dx[t]][y + dy[t]]){
		vis[x + dx[t]][y + dy[t]] = true;
		ans += dequy(x + dx[t], y + dy[t], n - 1);
		vis[x + dx[t]][y + dy[t]] = false;
	}
	return ans;
}

void solve(){
	int x, y, n; cin >> x >> y >> n;

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++) vis2[i][j] = false;

	vis[x][y] = true;
	cout << dequy(x, y, n) + (n % 2 == 0) << "\n";
	vis[x][y] = false;
}

int main(){
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;
}

/*
1
4 7 6
1
3 3 1
*/