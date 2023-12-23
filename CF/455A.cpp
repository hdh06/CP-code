#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

long long cnt[N] = {}; long long dp[N] = {};

int main(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		cnt[temp]++;
	}

	dp[1] = cnt[1]*1;
	for (long long i = 2; i < N; i++){
		dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i]*i);
	}
	cout << dp[N - 1];
	return 0;
}
