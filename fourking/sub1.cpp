#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll n; cin >> n;
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	for (ll j = 1; j <= n; j++)
	for (ll k = 1; k <= n; k++)	
	if (n % (i * j * k) == 0)
			ans ++;
	cout << ans << "\n";
}
int main(){
	// freopen("fourking.inp", "r", stdin);
	// freopen("fourking.out", "w", stdout);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}