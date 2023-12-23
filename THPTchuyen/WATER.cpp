#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const INF = INT_MAX;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {-1, 1, 0, 0};

int n, m;
int arr[N][N], f[N][N];

queue<array<int, 2> > myque;

bool check(int i, int j){
	return (1 <= i && i <= n && 1 <= j && j <= m);
}

int main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			f[i][j] = INF;
			if (i == n || j == m || i == 1 || j == 1){
				f[i][j] = arr[i][j];
				myque.push({i,j});
			}
		}
	}

	while (!myque.empty()){
		int i = myque.front()[0], j = myque.front()[1];

		myque.pop();

		for (int t = 0; t < 4; t++){
			int x = i + dx[t], y = j + dy[t];
			if (check(x,y)){
				int w = max(f[i][j], arr[x][y]);
				if (f[x][y] > w){
					f[x][y] = w;
					myque.push({x, y});
				}
			}
		}
	}	

	int tong = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			tong += f[i][j] - arr[i][j];
			// cout << f[i][j] << " ";
		}

		// cout << endl;
	}

	cout << tong;

	return 0;
}