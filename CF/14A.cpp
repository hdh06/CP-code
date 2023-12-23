#include <bits/stdc++.h>

using namespace std;

int main(){
	int x = 51, y = 51, u = 0, v = 0; 	
	int n, m; cin >> n >> m;
	char arr[51][51];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			if (arr[i][j] == '*')
				x = min(x, i), y = min(y, j),
				u = max(u, i), v = max(v, j);
		}

	for (int i = x; i <= u; i++){
		for (int j = y; j <= v; j++)
			cout << arr[i][j];
		cout << "\n";
	}
	return 0;
}