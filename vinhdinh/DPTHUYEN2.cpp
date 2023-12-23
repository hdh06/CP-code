#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<array<int, 2> > arr(n);
	for (auto &x: arr) cin >> x[0] >> x[1];

	sort(arr.begin(), arr.end());

	vector<int> f(n + 1, INT_MAX); f[0] = INT_MIN;

	int ans = 0;

	for (auto x: arr){
		int k = upper_bound(f.begin(), f.end(), x[1]) - f.begin();
		f[k] = x[1];
		ans = max(ans, k);
	}

	cout << n - ans;
	return 0;
}