#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll k, vector<ll> arr){
	int n = arr.size();
	ll ans = 0;
	arr.push_back(LLONG_MAX);
	for (int i = 0; i < n; i++)
		ans += min(k, arr[i + 1] - arr[i]);
	return ans;
}

void solve(){
	int n; ll h; cin >> n >> h;
	vector<ll> arr(n);
	for (auto &x: arr) cin >> x;

	ll ans = -1;
	for (ll l = 0, r = 1e18; l <= r;){
		ll mid = (l + r) >> 1;
		if (f(mid, arr) >= h){
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}