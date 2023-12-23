#include <bits/stdc++.h>

using namespace std;

typedef array<int, 4> a3;

int const dx[4] = {1,  1, -1,-1};
int const dy[4] = {1, -1, -1, 1};

int INF = INT_MAX;
int const N = 501;
bool bc[N][N];
bool isvisited[N][N][4];
int dis[N][N][4];

// ofstream fo("File.out");

int n, m, p, q, s, t;
bool check(int i, int j){
	if (bc[i][j]) return false;
	return (1 <= i) && (i <= n) && (1 <= j) && (j <= n);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p >> q >> s >> t;

	while (m--){
		int i, j;
		cin >> i >> j;

		bc[i][j] = true;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int r = 0; r < 4; r++){
				dis[i][j][r] = INF;
			}
		}
	}

	priority_queue<a3> myque;

	dis[p][q][3] = 0;
	dis[p][q][2] = 0;
	dis[p][q][1] = 0;
	dis[p][q][0] = 0;
	myque.push({0, p, q, 0});
	myque.push({0, p, q, 1});
	myque.push({0, p, q, 2});
	myque.push({0, p, q, 3});

	while (!myque.empty()){
		a3 topp = myque.top();
		int wv = -topp[0];
		int i = topp[1], j = topp[2];
		int curr = topp[3];

		myque.pop();

		// fo << "c" << i << " " << j << " " << check(i,j) << " " << isvisited[i][j] << endl;

		if (isvisited[i][j][curr]) continue;
		isvisited[i][j][curr] = true;

		if (dis[i][j][curr] < wv) continue;

		for (int r = 0; r < 4; r++){
			int x = i + dx[r], y = j + dy[r];
			if (r != curr && check (x,y) && dis[x][y][r] > wv + 1){
				dis[x][y][r] = wv + 1;
				myque.push({-dis[x][y][r], x, y, r});
			}

			if (r == curr && check (x,y) && dis[x][y][r] > wv){
				dis[x][y][r] = wv;
				if (i == p && j == q) dis[x][y][r] ++;
				myque.push({-dis[x][y][r], x, y, r});
			}
		}

		if (i == s && j == t){
		 	continue;
		}
	}

	int maxn = min({dis[s][t][0], dis[s][t][1],dis[s][t][2], dis[s][t][3]});
	// cout << dis[s][t][0] << " " <<  dis[s][t][1] << " " << dis[s][t][2] << " " << dis[s][t][3] << endl;

	cout << (maxn == INF? -1: maxn);
	return 0;
}

/*
5 5 5 5 5 3
1 2
1 5
2 2
4 2
4 3 */