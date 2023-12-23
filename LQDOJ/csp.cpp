#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	sort(arr.begin() + 1, arr.end());

	long long ans = 0;

	for (int i = 1; i <= n; i++){
		int k = upper_bound(arr.begin(), arr.begin() + i, m - arr[i]) - arr.begin() - 1;
		ans += k;
	}

	cout << ans;
	return 0;
}