#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii;

int const N = 1001;
int const INF = INT_MAX;

int dx[] = {0, 1, 0, -1, -0};
int dy[] = {0, 0, 1, -0, -1};

int n, m;
bool arr[N][N], vis[N][N] = {};
int dis[N][N];

int main(){
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			dis[i][j] = INF;
		}
	}
	
	priority_queue<iii> myque; //tu quy i

	dis[1][1] = 0 + (arr[1][1] == 0); 

	myque.push({-dis[1][1], 1, 1});
	
	while(!myque.empty()){
		iii ptop = myque.top();
		int i = ptop[1], j = ptop[2];

		myque.pop();

		if (vis[i][j]) continue;
		vis[i][j] = true;

		for (int t = 1; t <= 4; t++){
			int g = i + dx[t], h = j + dy[t], s = (arr[g][h] + dis[i][j] + 1)%2;
			if (!(1 <= g && g <= n && 1 <= h && h <= m)) continue;
			if (s == 0){
				if (dis[g][h] > dis[i][j] + 2){
					dis[g][h] = dis[i][j] + 2;
					myque.push({-dis[g][h], g, h});
				}
			}
			else{
				if (dis[g][h] > dis[i][j] + 1){
					dis[g][h] = dis[i][j]  + 1;
					myque.push({-dis[g][h], g, h});
				}
			}
		}
	}

	cout << dis[n][m];
	
	return 0;
}