#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int main(){
	int n; cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];	

	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	int tong = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i - 1; j >= 0; j--)
			if (arr[i] > arr[j]) 
				(dp[i] += dp[j]) %= MOD;
		(tong += dp[i]) %= MOD;
	}

	cout << tong;
	return 0;
}