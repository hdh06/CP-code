#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii;

int const N = 11, M = 2223;
int const dx[] = {-1, 0, 0, +1}; // 0: up, 1: right, 2: left, 3: down
int const dy[] = {0, -1, +1, 0};
int const INF = INT_MAX;

int dis[M][N] = {};
bool vis[M][N] = {};
int arr[M][N][4] = {};

int n, m;

bool check(int x, int y){
	return (1 <= x && x <= m && 1 <= y && y <= n);
}

int main(){
	
	cin >> m >> n;

	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			for (int t = 0; t < 4; t++) arr[i][j][t] = -1;
			dis[i][j] = INF;
		}
	}

	for (int t = 1, i = 1; t < 2*m + 1; t++){
		if (t % 2 != 0){
			for (int j = 1; j <= n; j++){ 
				cin >> arr[i - 1][j][3];
				arr[i][j][0] = arr[i - 1][j][3];			
			}
		}
		else{
			for (int j = 2; j <= n; j++){
				cin >> arr[i][j - 1][2];
				arr[i][j][1] = arr[i][j - 1][2]; 
			}
			i++;
		}
	}


	priority_queue<iii> myque;

	for (int j = 1; j <= n; j++){
		dis[0][j] = 0;
		myque.push({0, 0, j});
	}

	while (!myque.empty()){
		int i = myque.top()[1], j = myque.top()[2];
		myque.pop();

		if (vis[i][j]) continue;
		vis[i][j] = true;

		for (int t = 0; t < 4; t++){
			int g = i + dx[t], h = j + dy[t];
			// cout << "[" << i << "][" << j << "] -> [" << g << "][" << h << "] ";
			if (check(g, h) && arr[i][j][t] != -1 && dis[g][h] > dis[i][j] + arr[i][j][t]){
				// cout << "YES "; 
				dis[g][h] = dis[i][j] + arr[i][j][t];
				myque.push({-dis[g][h], g, h});
			}// else cout << "NO ";
			// cout << "reason: " << check(g, h) << " " << (arr[i][j][t] != -1) << " " << (dis[g][h] > dis[i][j] + arr[i][j][t]) << endl;
			
		}
	}

	// for (int i = 0; i <= m; i++)
	// 	for (int j = 1; j <= n; j++) cout << dis[i][j] << " \n"[j == n];
	cout << dis[m][n];
	return 0;
}