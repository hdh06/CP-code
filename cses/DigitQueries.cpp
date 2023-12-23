#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll k){
	ll dem = 0;
	ll t = 0;
	ll next = 0;
	for(ll b = 9; t + b*(dem + 1) < k; b *= 10, dem ++) t += b*(dem + 1), next = next*10 + 9;

	ll d = dem + 1;
	ll b = pow(10, dem);
	while(b > 0){
		while(t + d*b < k){
			t += d*b;
			next += b;
		}
		b /= 10;
	}

	// cout << "BEDBUG: " << t << " " <<  << endl;
	next ++;
	for (ll x = d - (k - t); x--;) next /= 10;
	return (next % 10);
}

int main(){
	int q;
	cin >> q;
	while(q --){
		ll k;
		cin >> k;

		cout << solve(k) << endl;
	}
	return 0;
}