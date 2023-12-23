#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int const dx[] = {1, -1, 0, 0};
int const dy[] = {0, 0, 1, -1};

bool isvisited[N][N];

char arr[N][N];

int f, c, m, n;

bool check(int i, int j){
	return (1 <= i && i <= n && 1 <= j && j <= m);
}

void DFS(int i, int j){
	if(!check(i,j)) return;
	if(isvisited[i][j]) return; 
	isvisited[i][j] = true;

	if (arr[i][j] == '#') return;
	if (arr[i][j] == 'f') f++;
	if (arr[i][j] == 'c') c++;
	
	for (int t = 0; t < 4; t++){
		DFS(i + dx[t], j + dy[t]);
	}
}

int main(){
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}

	int ans_f = 0, ans_c = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			f = 0, c = 0;
			DFS(i, j);
			// cout << f << " " << c << endl;
			if (f >= c) ans_f += f;
			else ans_c += c;
		}
	}

	cout << ans_f << " " << ans_c;
	return 0;
}