#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n), b(1, INT_MIN);

	for (auto &x: arr) cin >> x;

	int maxn = 0;
	for (auto x: arr){
		int k = lower_bound(b.begin(), b.end(), x) - b.begin();
		if (k == b.size()) b.push_back(x);
		else b[k] = x;

		maxn = max(maxn, k);
	}	

	cout << maxn;

	// vector<int> arr = {0, 1, 2, 3, 3, 4, 5};
	// cout << upper_bound(arr.begin(), arr.end(), 3) - arr.begin() << endl;
	return 0;
}