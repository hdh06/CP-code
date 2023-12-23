#include <bits/stdc++.h>

using namespace std;

// |-| |) |-|

int const N = 1001;

int main(){
	freopen("DAYSO.inp", "r", stdin);
	freopen("DAYSO.out", "w", stdout);

	int n; 
	cin >> n;	

	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dp[N] = {};

	int ans = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) if (arr[i] > arr[j]){
			dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
	return 0;
}