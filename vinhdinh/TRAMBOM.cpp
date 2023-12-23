#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int main(){
	int n, k;
	cin >> n >> k;

	int arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	sort(arr + 1, arr + n + 1);

	int minn = INT_MAX;
	for (int i = k; i <= n; i++){
		minn = min(minn, arr[i] - arr[i - k + 1]);
	}

	cout << minn;
	return 0;
}