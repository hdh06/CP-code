#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const V = 1001;
int const dx[] = {0, 0, 1, -1};
int const dy[] = {1, -1, 0, 0};

bool biome[N][N], vis[N][N]; 
int lvl[N][N];
int n, m;

bool check(int i, int j){
	return (1 <= i && i <= n && 1 <= j && j <= m);
}

void DFS(int i, int j, int k){
	if (!check(i, j)) return;

	// cout << "BEDBUG " << i << " " << j << endl;

	if (lvl[i][j] > k){
		return;
	} 

	if (biome[i][j] == 1 && lvl[i][j] == k){
		return;
	}

	lvl[i][j] = k;
	biome[i][j] = 1;

	for (int t = 0; t < 4; t++){
		DFS(i + dx[t], j + dy[t], k);
	}
}

void DFS(int i, int j){
	if (!check(i, j)) return;
 
	if (biome[i][j] == 1) return;
	
	if (vis[i][j]) return;
	vis[i][j] = true;

	for (int t = 0; t < 4; t++){
		DFS(i + dx[t], j + dy[t]);
	}
}

int main(){
	cin >> n >> m; int CASE = 1;
	while (n != 0 && m != 0){
		int maxV = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> lvl[i][j];
				maxV = max(maxV, lvl[i][j]);
				biome[i][j] = 0;
			}
		}


		bool flag = false;
		for (int k = 1; k <= maxV; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					if (i == 1 || j == 1 || i == n || j == m){
						DFS(i, j, k);
					}
					vis[i][j] = false;
				}
			}
			int dem = 0;
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					if (!vis[i][j] && biome[i][j] == 0){
						DFS(i,j);
						dem++;
					}
				}
			}
			if(dem > 1) {
				cout << "Case " << CASE <<": Island splits when ocean rises " << k  << " feet."<< endl;
				flag = true;
				break;
			}

			// cout << "DEBUG " << k << endl;
			// for (int i = 1; i <= n; i++){
			// 	for (int j = 1; j <= m; j++){
			// 		cout << biome[i][j] << " \n"[j == m];
			// 	}
			// }

			// cout << "DEBUG " << k << " " << dem << endl;
			// cout << "BEDBUG " << k << endl;
		}

		if (!flag) cout << "Case " << CASE << ": Island never splits." << endl;
		cin >> n >> m;
		CASE ++;
	}
	return 0;
}