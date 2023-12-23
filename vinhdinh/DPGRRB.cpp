#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int const MOD = 1e9 + 7;

int arr[N][N] = {};

int main(){
	int n , m , p;
	cin >> n >> m >> p;	

	arr[1][1] = 1;

	while(p--){
		int i, j;
		cin >> i >> j;

		arr[i][j] = -1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (arr[i][j] != -1){
			if (arr[i - 1][j] != -1) arr[i][j] += arr[i - 1][j] , arr[i][j] %= MOD;
			if (arr[i][j - 1] != -1) arr[i][j] += arr[i][j - 1] , arr[i][j] %= MOD;
		}

	cout << (arr[n][m] == -1? 0: arr[n][m]);
	return 0;
}