#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool f(ll d, int mx, vector<int> arr){
	ll c2 = d / 2, c1 = d - c2;
	for (auto x: arr){
		int z = mx - x;
		if (z / 2 <= c2){
			c2 -= z / 2;
			c1 -= z % 2;
		}else{
			c1 -= z - c2 * 2;
			c2 = 0;
		}
	}
	return (c1 >= 0);
}

void solve(){
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	int maxx = *max_element(arr.begin(), arr.end());
	ll res = LLONG_MAX;
	for (int mx = maxx; mx <= maxx + 1; mx++){
		ll l = 0, r = 1e16, ans = -1;
		while (l <= r){
			ll mid = (l + r) >> 1;
			if (f(mid, mx, arr)){
				r = mid - 1;
				ans = mid;
			}
			else l = mid + 1;
		}
		res = min(res, ans);
	}	
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}