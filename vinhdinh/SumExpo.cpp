#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> p;

void init(){
	ll const n = 2e6;
	bool sang[n] = {1, 1};
	for (ll i = 2; i < n; i++) if (!sang[i]){
		for (ll j = i*i; j < n; j += i) sang[j] = true;
		p.push_back(i);
	}
}

int main(){
	init();
	ll n; cin >> n;

	int d = 0;

	ll S = 0, P = 0;

	while (n > 1){
		ll dem = 0;
		while (n % p[d] == 0){
			n /= p[d];
			dem++;
		}

		if (d == p.size() - 1){
			P += 1;
			break;
		} 

		if (dem&1) P += dem;
		else S += dem;

		d++;
	}

	cout << S << "\n" << P;
	return 0;
}