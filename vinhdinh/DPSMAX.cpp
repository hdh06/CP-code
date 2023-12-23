#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

int main(){
	int n;
	cin >> n;

	int arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	long long dp[N] = {};

	for (int i = 1; i <= n; i++){
		dp[i] = arr[i];
		for (int j = i - 1; j >= 1; j--){
			if (arr[j] <= arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}