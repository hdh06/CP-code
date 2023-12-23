#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int maxn = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		maxn = max(maxn, arr[i]);
	}
	int tong = 0;
	for (int i = 0; i < n; i++){
		tong += maxn - arr[i];
	}
	cout << tong;
	return 0;
}