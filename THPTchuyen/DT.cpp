#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {-1, 1, 0, 0};

char graph[N][N];
bool isvisited[N][N];

int n, m;

bool check(int i, int j){
	return (1 <= i && i <= n && 1 <= j && j <= m && graph[i][j] != '#');
}

// void DFS(int i, int j){
// 	if (!check(i , j)) return;
// 	if (isvisited[i][j]) return;
// 	isvisited[i][j] = true;

// 	// cout << i << " " << j << endl;

// 	for (int t = 0; t < 4; t++){
// 		int x = i + dx[t], y = j + dy[t];
// 		DFS(x, y);
// 	}
// }

void BFS(int g, int h){
	queue<pair<int, int> > myque;
	myque.push({g, h});

	while (!myque.empty()){
		int i = myque.front().first, j = myque.front().second;

		myque.pop();

		// cout << i << " " << j << endl;

		if (!check(i, j)) continue;
		if (isvisited[i][j]) continue;
		isvisited[i][j] = true;

		for (int t = 0; t < 4; t++){
			int x = i + dx[t] , y = j + dy[t];
			myque.push({x, y});
		}
	}
}

int main(){
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> graph[i][j];
			isvisited[i][j] = false;
		}
	}

	int dem = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (check(i,j) && !isvisited[i][j]) dem++;
			BFS(i, j);
			// cout << check(i, j) << " ";
		}

		// cout << endl;
	}
	
	cout << dem;
	return 0;
}


// // danh sach ke

// 5 6
// 1 2
// 2 3
// 2 4
// 5 1
// 4 5
// 1 3
	
// 1: 2 5 3
// 2: 1 3 4
// 3: 2 1
// 4: 2 5
// 5: 1 4
// 6: 

// // danh sach canh

// 1 2
// 2 3
// 2 4
// 5 1
// 4 5
// 1 3

// // ma tran ke
//   1 2 3 4 5 6
// 1 0 1 1 0 1 0
// 2 1 0 1 1 0 0
// 3 1 1 0 0 0 0
// 4 0 1 0 0 1 0
// 5 1 0 0 1 0 0
// 6 0 0 0 0 0 0

// ########
// #..#...#
// ####.#.#
// #..#...#
// ########