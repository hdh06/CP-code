#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll n, m, k;

ll mul(ll a, ll b){
	if (b == 0) return 0;
	ll ans = mul(a, b / 2) * (2 % m) % m;
	if (b & 1) return (ans + (a % m)) % m;
	return ans;
}

int main(){
 	cin >> n >> k >> m;
	if (n < k){
		cout << 0;
		return 0;
	}
	k++;
	bool y = 0;
	ll ans = 1;
	for (ll i = n + 1; i >= n + 1 - k + 1; i--){
		ll x = i;	
		if (!y && x % k == 0) x /= k, y = 1;
		ans = mul(ans, x);
	}
	cout << ans;
	return 0;
}