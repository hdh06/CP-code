#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int const N = 1001;
int const dx[] = {0, 0, 1, -1};
int const dy[] = {1, -1, 0, 0};
string const di = "RLDU";
char arr[N][N] , dir[N][N];
int dis[N][N], disA[N][N];
int n, m;
queue<ii> myque;
ii A;

bool check(int i, int j){
	return (1 <= i && i <= n && 1 <= j && j <= m);
}

int main(){
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			dis[i][j] = -1; disA[i][j] = -1;
			if (arr[i][j] == 'M'){
				myque.push({i,j});
				dis[i][j] = 0;
			}
			if (arr[i][j] == 'A') A[0] = i, A[1] = j, disA[i][j] = 0;
		}
	}

	ii E = {-1, -1};

	while (!myque.empty()){
		int i = myque.front()[0], j = myque.front()[1];
		myque.pop();

		for (int t = 0; t < 4; t++){
			int g = i + dx[t], h = j + dy[t];
			if(check(g, h) && arr[g][h] != '#' && dis[g][h] == -1){
				dis[g][h] = dis[i][j] + 1;
				myque.push({g, h});
			}
		}
	}

	myque.push(A);

	while(!myque.empty()){
		int i = myque.front()[0], j = myque.front()[1];
		myque.pop();

		if (i == n || j == m || i == 1 || j == 1){
			E = {i,j};
		}

		for (int t = 0; t < 4; t++){
			int g = i + dx[t], h = j + dy[t];
			if(check(g, h) && arr[g][h] != '#' && disA[g][h] == -1 && disA[i][j] + 1 < (dis[g][h] == -1?INT_MAX:dis[g][h])){
				disA[g][h] = disA[i][j] + 1;
				dir[g][h] = t;
				myque.push({g, h});
			}
		}
	}

	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= m; j++){
	// 		if (arr[i][j] == '#') cout << "# ";
	// 		else cout << (dis[i][j] == -1?9:dis[i][j]) << " ";
	// 	}
	// 	cout << endl;
	// }
	if (E[0] == -1 || disA[E[0]][E[1]] == -1) cout << "NO";
	else{
		cout << "YES" << endl;
		string ans;
		for (int i = E[0], j = E[1]; arr[i][j] != 'A'; ){
			for (int t = 0; t < 4; t++){
				if (dir[i][j] == t){
					ans.push_back(di[t]);
					i -= dx[t];
					j -= dy[t];
					break;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << endl << ans;
	}
	return 0;
}