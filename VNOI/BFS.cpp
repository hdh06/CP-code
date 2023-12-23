#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int graph[N][N];
bool isvisited[N][N];
int n, m;

int dis[N][N];

void BFS(int x, int y){
	queue<array<int, 3> > myque;

	myque.push({x, y});

	while (!myque.empty()) {
		int i = myque.front()[0], j = myque.front()[1];

		myque.pop();

		if (isvisited[i][j]) continue;
		isvisited[i][j] = true; 

		for (int t = 0; t < 4; t++){
			int g = i + dx[t], h = j + dy[t];
			dis[g][h] = min(dis[g][h], dis[i][j] + 1); 
			myque.push({g, h});
		}

	}


}

int main(){

	return 0;
}