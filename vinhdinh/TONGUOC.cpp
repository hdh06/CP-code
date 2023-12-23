#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll n){
	ll tong = 0, dem = 0;
	for (ll i = 1; i <= sqrt(n); i++) if (n % i == 0) tong += i + ((i != n/i)?n / i:0), dem += 1 + (i != n/i);
	cout << n << " co " << dem << " uoc. Tong uoc la: " << tong << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t; 
	while(t--){
		ll n; 
		cin >> n; 
		solve(n);
	}
	return 0;
}