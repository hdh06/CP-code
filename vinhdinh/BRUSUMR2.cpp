#include <bits/stdc++.h>

using namespace std;

int const N = 701;

int main(){
	int n, m, k;	
	int arr[N][N]; long long s[N][N] = {};
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + arr[i][j];
		}
	}

	long long maxn = LLONG_MIN;

	for (int i = k; i <= n; i++){
		for (int j = k; j <= m; j++){
			maxn = max(maxn, s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k] - (k > 2?(s[i - 1][j - 1] - s[i - k + 1][j - 1] - s[i - 1][j - k + 1] + s[i - k + 1][j - k + 1]):0));
		}
	}

	cout << maxn;

	return 0;
}