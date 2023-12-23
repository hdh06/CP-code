#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

string bit_hoa(ll x){
	string s; 
	while (x > 0LL){
		if (x & 1LL) s.push_back('1');
		else s.push_back('0');
		x >>= 1;
	}

	reverse(s.begin(), s.end());

	return s;
}

int main(){
	ll n; cin >> n;

	ll dem = 0;

	for (ll i = 0; i <= 63; i++){
		ll base = (1LL << i) - 1LL;
		for (ll j = 1; j + i + 1 <= 63; j++){
			if ((base | (((1LL << j) - 1LL)<<(i + 1))) <= n){
				dem++;
				// cout << i << " " << j << " " <<bit_hoa((base | (((1LL << j) - 1LL)<<(i + 1)))) << " " << (base | (((1LL << j) - 1LL)<<(i + 1))) << " " << base << " " << bit_hoa(base)<< "\n";
			}
		}
	}

	cout << dem;
	return 0;
}