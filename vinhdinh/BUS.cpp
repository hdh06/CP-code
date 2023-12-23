#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);

	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());

	long long tong = 0;

	for (auto x: arr){
		tong += x;
		k--;
		if (k == 0) break;
	}	

	cout << tong;
	return 0;
}