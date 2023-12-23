#include <bits/stdc++.h>

using namespace std;

int const N = 801;

typedef long long ll;

int main(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	ll arr[N][N] = {};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			if (i < x || j < y) arr[i][j] = 0;
		}

	for (int i = x; i <= n; i++){
		for (int j = y + (i == x); j <= m; j++){
			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) - arr[i][j];
		}
	}

	if (arr[n][m] >= 0) cout << "Y " << arr[n][m];
	else cout << "N";
	return 0;
}