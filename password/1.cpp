#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const MOD = 1e9 + 7;

int main(){
	int n, a, b; cin >> n >> a >> b;
	ll ans = 0;
	while (n--)
		ans = ans * 10 + 9;
	ans /= b;
	ans ++;
	cout << ans % MOD;
	return 0;
}