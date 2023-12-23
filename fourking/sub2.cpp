#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll n; cin >> n;
	vector<int> div;
	for (ll i = 1; i <= n; i++) if (n % i == 0) div.push_back(i);

	int sz = div.size();
	ll ans = 0;
	for (auto i: div)
		for (auto j: div) if ((n / i) % j == 0)
			for (auto k: div) if ((n / (1LL * i * j)) % k == 0)
					ans++;

	cout << ans << "\n";
}

int main(){
	// freopen("fourking.inp", "r", stdin);
	// freopen("fourking.out", "w", stdout);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}