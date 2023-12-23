#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int n, m;
char arr[N][N];

bool s(int x, int y){
	if (x < 1 || x > n || y < 1 || y > m) return 1;
	return arr[x][y] == '*';
}

bool isLegit(int x, int y){
	if (s(x + 1, y + 1) && s(x - 1, y + 1) && s(x, y + 2)) return 1;
	if (s(x - 1, y - 1) && s(x - 1, y + 1) && s(x - 2, y)) return 1;
	if (s(x + 1, y + 1) && s(x + 1, y - 1) && s(x + 2, y)) return 1;
	if (s(x - 1, y - 1) && s(x + 1, y - 1) && s(x, y - 2)) return 1;
	
	if (s(x + 1, y + 1) && s(x - 1, y - 1) && s(x - 1, y + 1) && s(x + 1, y - 1)) return 1;
	if (s(x + 1, y + 1) && s(x + 2, y) && s(x, y + 2) && s(x + 2, y + 2)) return 1;
	if (s(x + 1, y - 1) && s(x + 2, y) && s(x, y - 2) && s(x + 2, y - 2)) return 1;
	if (s(x - 1, y - 1) && s(x - 2, y) && s(x, y - 2) && s(x - 2, y - 2)) return 1;
	if (s(x - 1, y + 1) && s(x - 2, y) && s(x, y + 2) && s(x - 2, y + 2)) return 1;
	return 0;
}

void solve(){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) if (arr[i][j] == '*'){
			cerr << i << " " << j << '\n';
			if (!isLegit(i, j)){
				cout << "NO\n";
				return;
			}
		}
		
	}
	cout << "YES\n";
}

int main(){
	while (cin >> n >> m){
		solve();
	}	
	return 0;
}