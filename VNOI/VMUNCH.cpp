#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const INF = INT_MAX;
int const dx[4] = {0, 0, -1, 1};
int const dy[4] = {-1, 1, 0, 0};

bool arr[N][N];
int n, m;

bool check(int i, int j){
	return (1 <= i && i <= n && 1 <= j && j <= m && arr[i][j]);
}


int main(){
	cin >> n >> m;
	int s, t, q, p, dis[N][N];

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char temp;
			cin >> temp;
			if (temp == 'B') q = i, p = j, arr[i][j] = true;
			else if (temp == 'C') s = i, t = j, arr[i][j] = true;
			else arr[i][j] = (temp == '*'?0:1);
			dis[i][j] = INF;
		}
	}

	bool isvis[N][N];
	queue<pair<int, int> > myque;

	myque.push({s,t});

	dis[s][t] = 0;

	while (myque.size()){
		int i = myque.front().first, j = myque.front().second;

		myque.pop();
		
		if (isvis[i][j]) continue;
		isvis[i][j] = true;

		if (i == q && j == p) continue;

		for (int t = 0; t < 4; t++){
			int x = i + dx[t], y = j + dy[t];
			if (check(x, y) && dis[x][y] > dis[i][j] + 1){
				dis[x][y] = dis[i][j] + 1;
				myque.push({x, y});
			}
		}
	}

	cout << (isvis[q][p]?dis[q][p]:-1);
	return 0;
}
