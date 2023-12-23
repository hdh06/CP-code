#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int main(){
	int n; cin >> n;

	int dp[N][3] = {};
	for (int i = 1; i <= n; i++) cin >> dp[i][0];
	for (int i = 1; i <= n; i++) cin >> dp[i][1];
	for (int i = 1; i <= n; i++) cin >> dp[i][2];	

	int arr[3] = dp[1];

	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 3; j++){
			int pre = (j - 1) % 3, suf = (j + 1) % 3;
			dp[i][j] += max(dp[i][pre] + arr[pre], dp[i][suf] + arr[suf]);
		}
	}
	return 0;
}