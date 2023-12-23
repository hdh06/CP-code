#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> k >> n;

	vector<int> arr(n);	

	for (auto &x: arr) cin >> x;

	sort(arr.begin(),arr.end(), greater<int>());
	
	long long tong = 0;
	for (int i = 0; i < n && k--; i += 2){
		tong += arr[i]*arr[i + 1];
	}

	cout << tong;

	return 0;
}