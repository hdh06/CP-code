#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll spow(ll x, ll n){
	if (n == 0) return 1;

	ll ans = spow(x, n / 2);
	if (n % 2 == 0) return ans*ans;
	return ans*ans*x;
}

int main(){
	ll a, b, c, d, m, n, p, q;
	cin >> a >> b >> c >> d >> m >> n >> p >> q;

	cout << spow(a, m) + spow(b, n) + spow(c, p) + spow(d, q);
	return 0;
}