#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;
typedef long long ll;

int const N = 5001;

ll len(ii a){
	return a[1] - a[0] + 1;
}

int main(){
	int n;
	cin >> n;	

	ii arr[N];

	for (int i = 1; i <= n; i++){
		cin >> arr[i][0] >> arr[i][1];
	}

	sort(arr + 1, arr +n + 1);

	// for (int i = 1; i <= n; i++){
	// 	cout << arr[i][0] << " " << arr[i][1] << " " << len(arr[i]) << endl;
	// }

	ll dp[N] = {};

	for (int i = 1; i <= n; i++){
		dp[i] = len(arr[i]);
		for (int j = i - 1; j >= 1; j--) if (arr[j][1] < arr[i][0]){
			dp[i] = max(dp[i], dp[j] + len(arr[i]));
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}