#include <bits/stdc++.h>

using namespace std;
 
 typedef pair<int, int> ii;
 #define st first
 #define nd second
 
int dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
int dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};

int vis[9][9] = {};

bool isBreak = 0;

int pMove(int x, int y){
	int ans = 0;
	for (int t = 0; t < 8; t++){
		int new_x = x + dx[t], new_y = y + dy[t];
		if (new_x < 1 || new_x > 8 || new_y < 1 || new_y > 8) continue;
		if (vis[new_x][new_y]) continue;
		ans++;
	}
	return ans;
}

void dequy(int i, int j){
	vector<ii> z;
	for (int t = 0; t < 8; t++){
		int x = i + dx[t], y = j + dy[t];
		if (x < 1 || x > 8 || y < 1 || y > 8) continue;
		if (vis[x][y]) continue;
		z.push_back({x, y});
	}
	
	sort(z.begin(), z.end(), [](ii a, ii b){
		return pMove(a.st, a.nd) < pMove(b.st, b.nd);
	});
	
	for (auto x: z){
		vis[x.st][x.nd] = vis[i][j] + 1;
		dequy(x.st, x.nd);
		vis[x.st][x.nd] = 0;
		if (isBreak) return;
	}
	
	if (vis[i][j] == 64){
		for (int x = 1; x <= 8; x++)
			for (int y = 1; y <= 8; y++)
				cout << vis[x][y] << " \n"[y == 8];
		isBreak = 1;
	}
}

int main(){
	int x, y; cin >> y >> x;
	vis[x][y] = 1;
	dequy(x, y);
	return 0;
}