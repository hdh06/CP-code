#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	vector<array<int, 2> > arr(n);
	for (auto &x: arr) cin >> x[0] >> x[1];

	sort(arr.begin(), arr.end());

	ll s = 0, ans = 0;
	for (auto x: arr){
		s += x[0];
		ans += x[1] - s;
	}	

	cout << ans;
	return 0;
}