#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const MOD = 1e9 + 7;

int main(){
	ll n, m, a;

	cin >> n >> m >> a;

	ll dem_n = (n / a) + (n % a > 0);
	ll dem_m = (m / a) + (m % a > 0);

	cout << (dem_n*dem_m) % MOD;
	return 0;
}