#include <bits/stdc++.h>

using namespace std;

bool vis[101][101][101];
int x, y, k, m, sol;

void ff(int curX, int curY, int curK) {
	if (vis[curX][curY][curK] || curK > k) return;
	vis[curX][curY][curK] = true;

	sol = min(sol, abs(m - (curX + curY)));
	// case 1
	ff(x, curY, curK + 1);
	ff(curX, y, curK + 1);
	// case 2
	ff(0, curY, curK + 1);
	ff(curX, 0, curK + 1);
	// case 3
	int leftoverX = (curX + curY > y ? curX + curY - y : 0);
	int leftoverY = (curY + curX > x ? curY + curX - x : 0);

	ff(leftoverX, min(y, curY + curX), curK + 1);
	ff(min(x, curX + curY), leftoverY, curK + 1);
}

int main() {
	// freopen("pails.in", "r", stdin);
	// freopen("pails.out", "w", stdout);

	cin >> x >> y >> k >> m;
	sol = m;
	ff(0, 0, 0);
	cout << sol << '\n';
}