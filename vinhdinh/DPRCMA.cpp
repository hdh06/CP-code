#include <bits/stdc++.h>

using namespace std;

int const N = 2006;

int main(){
	int n;
	cin >> n;
	int arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dp[N][N] = {};	

	for (int i = n; i > 0; i--){
		for (int j = i; j <= n; j++){
			int y = n - abs(j - i);
			dp[i][j] = max(dp[i + 1][j] + arr[i]*y, dp[i][j - 1] + arr[j]*y);
		}
	}

	cout << dp[1][n];
	return 0;
}