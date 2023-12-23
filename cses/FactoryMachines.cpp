#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
int n, k;
vector<ll> arr;

bool f(ll t){
	ll sum = 0;
	for (auto x: arr){
		sum += t / x;
		if (sum >= k) return 0;
	}
	return 1;
}

ll tknp(ll l, ll r){
	if (l == r) return l;
	ll mid = (l + r) >> 1;
	// cout << l << " " << r << " " << calc(mid) << "\n";
	if (f(mid)) return tknp(mid + 1, r);
	return tknp(l, mid);
}

int main(){
 	cin >> n >> k;
 	arr.resize(n);
	for (auto &x: arr) cin >> x;	

	cout << tknp(1, (ll) 1e18);
	return 0;
}