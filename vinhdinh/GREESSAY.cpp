#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

int main(){
	int n; ll avg, s = 0, r; cin >> n >> r >> avg;
	avg *= n;	

	vector<array<int, 2> > arr(n);
	for (auto &x: arr){
		cin >> x[1] >> x[0];
		s += x[1];
	}

	sort(arr.begin(), arr.end());

	ll ans = 0;

	for (auto x: arr){
		ll d = max(0ll, r - x[1]);
		if (s + d >= avg) d = max(0ll, avg - s);
		s += d;
		ans += d * x[0];
	}

	cout << ans;
	return 0;
}