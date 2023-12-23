#include <bits/stdc++.h>

using namespace std;

int const N = 501;

int main(){
	int m, n;
	cin >> m >> n;
	vector<int> coins(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> coins[i];
	}
	int arr[N][N] = {};
	for (int i = 1; i <=n ;i++){
		for (int j = 1; i <= m; i++){
			arr[i][j] = N;
			if (j >= coins[i]){
				arr[i][j] = min(arr[i - 1][j], arr[i][j - coins[i]] + 1);
			}
			else arr[i][j] = arr[i - 1][j];
		}
	}
	return 0;
}