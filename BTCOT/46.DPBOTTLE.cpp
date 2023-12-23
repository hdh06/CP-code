#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 4;

int main(){
	int n;
	cin >> n;
	long long dp[N];

	long long arr[N], sz[N];

	cin >> arr[1] >> arr[2];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	sz[1] = 1;
	sz[2] = 2;
	sz[0] = 0;
	int dem = 1;
 	for (int i = 3; i <= n; i++){
 		cin >> arr[i];
 		dp[i] = max({dp[i - 1],dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1]});
 		sz[i] = INT_MAX;
 		if (dp[i - 1] == dp[i]) sz[i] = min(sz[i], sz[i - 1]);
 		if (dp[i - 2] + arr[i] == dp[i]) sz[i] = min(sz[i], sz[i - 2] + 1);
 		if (dp[i - 3] + arr[i] + arr[i - 1] == dp[i]) sz[i] = min(sz[i], sz[i - 3] + 2);

 		// cout << dp[i - 1] << " " << dp[i - 2] + arr[i] << " " <<  dp[i - 3] + arr[i] + arr[i - 1] << " " << dp[i] << endl;

 	}

 	//for (int i = 1; i <= n; i++) cout << sz[i] << endl;
 	cout << sz[n] << " " << dp[n];
	return 0;
}
    