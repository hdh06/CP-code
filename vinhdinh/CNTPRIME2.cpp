#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll L, R; cin >> L >> R;
	ll lim = sqrtl(R);
	
	vector<ll> prime;
	vector<bool> sieve(lim + 1, 1);
	for (ll i = 2; i <= lim; i++) if (sieve[i]){
		for (ll j = i * i; j <= lim; j += i) sieve[j] = 0;
		prime.push_back(i);
	}
	
	vector<bool> ssieve(R - L + 1, 1);
	for (auto x: prime){
		for (ll i = max(x * x, (L + x - 1) / x * x); i <= R; i += x) 
			ssieve[i - L] = 0;
	}
	
	int cnt = 0;
	for (auto x: ssieve) cnt += x;
	cout << cnt - (L == 1);
	return 0;
}