#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	cin >> arr[0];

	long long tong = arr[0]/k;
	arr[0] %= k;
	for (int i = 1; i < n; i++){
		cin >> arr[i];
		long long temp = min(arr[i - 1] + arr[i], k);
		arr[i] -= (temp - arr[i - 1]);
		// arr[i - 1] = 0;
		tong += (temp != 0);
		tong += arr[i] / k;
		arr[i] %= k; 
		// cout << arr[i] << " " << arr[i - 1] << " " << temp << endl;
	}

	tong += (arr[n - 1] != 0);

	cout << tong;
	return 0;
}