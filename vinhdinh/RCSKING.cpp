#include <bits/stdc++.h>

using namespace std;

int const dx[] = {-1, -1, -1, 1, 1, 1,  0, 0};
int const dy[] = {-1,  0,  1,-1, 0, 1, -1, 1};

int n;
int a, b, c, d;
int x, y, z, t;

bool vis[1001][1001] = {};

bool check(int a, int b, int x, int y){
	if (a == -1 && b == -1) return false;
	if (a == x || b == y) return true;
	if (abs(a - x) == abs(b - y)) return true;
	return false;
}

bool dequy(int x, int y){
	if (x < 1 || x > n || y < 1 || y > n) return false;
	if (check(a, b, x, y) || check(c, d, x, y)) return false;
	if (x == z && y == t) return true;

	if (vis[x][y]) return false;
	vis[x][y] = true;

	bool ans = 0;
	for (int t = 0; t < 8; t++){
		ans |= dequy(x + dx[t], y + dy[t]);
	}
	return ans;
}

int main(){
	cin >> n;
	cin >> a >> b >> c >> d;
	cin >> x >> y >> z >> t;

	bool flag = false;
	for (int t = 0; t < 8; t++){
		int g = x + dx[t], h = y + dy[t];
		if (g == a && h == b && !check(a, b, c, d)){
			x = g, y = h;
			a = -1, b = -1;
			flag = true;
			break;
		}
		if (g == c && h == d && !check(a, b, c, d)){
			x = g, y = h;
			c = -1, d = -1;
			flag = true;
			break;
		}
	}
	if (!flag && (check(a, b, x, y) || check(c, d, x, y))){
		for (int t = 0; t < 8; t++){
			int g = x + dx[t], h = y + dy[t];
			if (g < 1 || g > n || h < 1 || h > n) continue;
			if (!check(a, b, g, h) && !check(c, d, g, h)){
				x = g, y = h;
				break;
			}
		}
	}

	cout << (dequy(x, y)?"YES":"NO"); 
	return 0;
}