#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n; cin >> n;
	ll tong = 0;
	for (ll t = n; t > 0;tong += t % 10, t /= 10);
	cout << (n % tong == 0);
	return 0;
}