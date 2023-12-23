#include <bits/stdc++.h>

using namespace std;

int const N = 5001;
int const MOD = 1000000007;

int main(){
	int n;
	cin >> n;

	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dp[N] = {}, xam[N] = {}, maxn = 0, maxd= 0;

	for (int i = 1; i <= n; i++){
		xam[i] = 1; dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) if (arr[j] < arr[i]){
			if (xam[i] < xam[j] + 1){
				dp[i] = 0;
				xam[i] = xam[j] + 1;
			}
			
		}

		for (int j = i - 1; j >= 1; j--){
			if (arr[j] < arr[i] && xam[i] == xam[j] + 1){
				dp[i] += dp[j]; dp[i] %= MOD;
			}
		}
	}

	// for (int i = 1; i <= n; i++) cout << xam[i] << " \n"[i==n];
	// for (int i = 1; i <= n; i++) cout << dp[i] << " \n"[i==n];

	maxn = *max_element(xam + 1, xam + n + 1);
	for (int i = 1; i <= n; i++) if (xam[i] == maxn) maxd += dp[i] , maxd %= MOD;
	cout << maxd;
	return 0;
}