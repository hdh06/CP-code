#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;

	vector<ll> arr(n), f(n + 1, INT_MAX);

	for (auto &x: arr) cin >> x;

	f[0] = INT_MIN;

	int ans = 0;
	for (auto x: arr){
		int k = lower_bound(f.begin(), f.end(), x) - f.begin();

		f[k] = x;
		ans = max(ans, k);
	}	

	cout << ans;
	return 0;
}