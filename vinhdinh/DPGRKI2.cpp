#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

long long arr[N][N] = {};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) arr[i][j] = LLONG_MIN;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}

	long long maxn = LLONG_MIN;
	for (int j = 2; j <= m; j++)
		for (int i = 1; i <= n; i++){
			arr[i][j] += max({arr[i - 1][j - 1], arr[i][j - 1], arr[i + 1][j - 1]});
			if (j == m) maxn = max(maxn, arr[i][j]);
		}

	cout << maxn;
	return 0;
}