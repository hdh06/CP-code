#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll spow(ll x, ll n){
	if (n == 0) return 1;

	ll ans = spow(x, n / 2);
	if (n % 2 == 0) return ans*ans;
	return ans*ans*x;
}

ll calc(ll m, ll n){
	ll tong = 0;
	for (int i = 1; i <= m; i++){
		tong += spow(i, n);
	}
	return tong;
}

int main(){
	ll m ,n;
	cin >> m >> n;
	cout << calc(m,n) << endl;
	return 0;
}