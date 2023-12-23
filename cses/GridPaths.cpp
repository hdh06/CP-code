#include <bits/stdc++.h>

using namespace std;

string const dir = "ULDR";
int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, -1, 0, 1};

string s;

bool check(int x, int y){
	return 1 <= x && x <= 7 && 1 <= y && y <= 7;
}

bool vis[10][10] = {};

int dequy(int i, int x, int y){
	// cout << i << " " << x << " " << y << "\n";
	if (i == s.size()){
		if (x == 1 && y == 7) return 1;
		return 0;
	}

	int ans = 0;

	for (int t = 0; t < 4; t++) if (dir[t] == s[i] || s[i] == '?'){
		int g = x + dx[t], h = y + dy[t];
		if (!check(g, h)) continue;
		// if (s[i] == '?'){
		// 	int a = x + dx[(t + 1) % 4];
		// 	int b = y + dy[(t + 1) % 4];
		// 	int c = x + dx[(t - 1) % 4];
		// 	int d = y + dy[(t - 1) % 4];
		// 	if (check(a, b) && check(c, d))
		// 		if (vis[g][h] && !vis[a][b] && !vis[c][d]) return 0;
		// }

		if (vis[g][h]) continue;

		vis[g][h] = true;
		ans += dequy(i + 1, g, h);
		vis[g][h] = false;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cout.tie(nullptr);
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> s;
	cout << dequy(0, 1, 1);
	return 0;
}