#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	array<long long, 2> arr[10001]; long long f[10001][2];

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	f[1][0] = arr[1][0];
	f[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++){
		f[i][0] = max(f[i - 1][0] + abs(arr[i - 1][1] - arr[i][1]), f[i - 1][1] + abs(arr[i - 1][0] - arr[i][1])) + arr[i][0];
		f[i][1] = max(f[i - 1][0] + abs(arr[i - 1][1] - arr[i][0]), f[i - 1][1] + abs(arr[i - 1][0] - arr[i][0])) + arr[i][1];
	}

	// f[n][0] += arr[n][1];
	// f[n][1] += arr[n][0];

	cout << max(f[n][0], f[n][1]);

	return 0;
}