#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int main(){
	int n, k;
	cin >> n >> k;

	vector<ii> arr(n);

	for (auto &x: arr) cin >> x[0];
	for (auto &x: arr) cin >> x[1];

	sort(arr.begin(), arr.end(), [](ii a, ii b){return a[0] - a[1] < b[0] - b[1];});
	
	long long tong = 0, i = 0;
	for (;arr[i][0] <= arr[i][1] && i < n; i++) tong += arr[i][0];
	for (;i < k && i < n; i++) tong += arr[i][0];
	for (;i < n; i++) tong += arr[i][1];

	cout << tong;
	return 0;
}