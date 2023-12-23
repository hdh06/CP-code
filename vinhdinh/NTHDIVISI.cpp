#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll lcm = a/gcd(a, b)*b;
	ll t = n/((a*lcm + b*lcm - a*b)/(a*b));
	ll k = n - t*(a*lcm + b*lcm - a*b)/(a*b);
	// vector<ll> p;
	// p.push_back(lcm*t);
	// for (int i = lcm*t + a; i < lcm*(t + 1); i += a){
	// 	p.push_back(i);
	// }

	// for (int i = lcm*t + b; i < lcm*(t + 1); i += b){
	// 	p.push_back(i);
	// }

	// sort(p.begin(), p.end());

	// cout << "t: " << t << " k: " << k  << " lcm: " << lcm << endl;

	// for (auto x: p) cout << x << " ";

	// cout << p[k];

	for (ll x = lcm*t, y = lcm*t;; k--){
		if (k == 0){
			cout << (max(x, y) > (ll)1e18?-1:max(x, y));
			break;
		}
		if (x + a <= y + b) x += a;
		else y += b;
		// cout << x << " " << y << endl;
	}

	return 0;
}