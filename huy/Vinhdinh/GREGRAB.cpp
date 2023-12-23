#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(n, 0);
	long long tong = 0, left_over;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	tong = arr[i] / k;
	arr[i] %= k;
	for (int i = 1; i < n; i++){
		tong += arr[i] / k;
		arr[i] %= k; 
		tong += (arr[i] + arr[i - 1])
	}
	return 0;
}