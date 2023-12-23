#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	if (k > n){
		cout << -1;
		return 0;
	}

	if (k == n){
		cout << "0 0";
		return 0;
	}

	vector<int> arr(n);

	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());

	int t = n - k - 1;
	cout << arr[t] + 1 << ' ' << arr[t] + 1;
	return 0;
}