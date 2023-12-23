#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x; cin >> n >> x;
	vector<int> arr(n);
	for (auto &t: arr) cin >> t;

	sort(arr.begin(), arr.end());	

	cout << n - (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
	return 0;
}