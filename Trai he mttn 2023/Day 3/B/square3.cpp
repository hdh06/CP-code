#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const V = 1e6 + 1;

ll cnt[V];

ll f(ll x){
	ll ans = 1;
	for (ll i = 2; i <= sqrt(x); i++){
		int dem = 0;
		while (x % i == 0) x /= i, dem++;
		if (dem & 1) ans *= i;
	}
	if (x > 0) ans *= x;
	return ans;
}

ll merge(ll x, ll y){
	ll g = gcd(x, y);
	return (x / g) * (y / g);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ll> arr(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] = f(arr[i]);
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++){
		ans += cnt[arr[i]];
		for (int j = 1; j < i; j++){
			ll ans = merge(arr[i], arr[j]);
			if (ans > V) continue;
			cnt[ans] ++;
		}
	}

	cout << ans;
	return 0;
	
}