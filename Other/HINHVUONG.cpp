#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 101;

int main(){
	int n;
	cin >> n;

	ll arr[N][N];

	ll sum[N][N] = {};

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	ll maxn = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int t = 1; t <= min(i, j); t++){
				if (t <= 2) maxn = max(maxn, sum[i][j] - sum[i - t][j] - sum[i][j - t] + sum[i - t][j - t]);
				else{
					maxn = max(maxn, sum[i][j] - sum[i - t][j] - sum[i][j - t] + sum[i - t][j - t] - (sum[i - 1][j - 1] - sum[i - t + 1][j - 1] - sum[i - 1][j - t + 1] + sum[i - t + 1][j - t + 1]));
				}
			}
		}
	}

	cout << maxn;

	return 0;
}

/*
5
1 -1 3 -2 1
-5 6 -3 3 -2
6 1 20 1 1
-4 -2 8 7 5
-6 0 4 -1 10
*/