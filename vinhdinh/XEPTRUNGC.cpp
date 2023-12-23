#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;

ll arr[N] = {};
ll n, k;
ll res = LLONG_MAX;

ll check(ll m){
	ll tong = 0, dem = 1;
	for (int i = 1; i <= n; i++){
		// if (arr[i] > m) return false;
		if (tong + arr[i] <= m){
			tong += arr[i];
		}
		else{
			tong = arr[i];
			dem++;
			if (dem > k) return false;
		}
	}
	return true;
}

void tknp(ll l, ll r){
	while (l <= r){
		ll mid = (l + r) >> 1;

		if (check(mid)){
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	ll tong = 0, maxn = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		tong += arr[i];
		maxn = max(maxn, arr[i]);
	}
	tknp(maxn, tong);
	cout << res;
	return 0;
}