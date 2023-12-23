#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
typedef array<int, 2> ii;

int main(){
	int n; 
	cin >> n;

	ii arr[N];

	for (int i = 1; i <= n; i++){
		cin >> arr[i][0] >> arr[i][1];
	}

	sort(arr + 1, arr + n + 1, [](ii a, ii b){return (a[1] - a[0]) > (b[1] - b[0]);});

	int dp[N] = {};

	// for (int i = 1; i <= n; i++) cout << arr[i][0] << " " << arr[i][1] << endl;

	for (int i = 1; i <= n; i++){
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--){
			if (arr[j][0] <= arr[i][0] && arr[i][1] <= arr[j][1]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}