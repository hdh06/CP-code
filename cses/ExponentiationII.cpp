#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int mpow(int x, int n, int m){
	if (n == 0) return 1 % m;
	int ans = mpow(x, n / 2, m);
	if (n & 1) return 1LL * ans * ans % m * x % m;
	return 1LL * ans * ans % m;

}

int main(){
	int t; cin >> t;
	while (t--){
		int a, b, c; cin >> a >> b >> c;
		cout << mpow(a, mpow(b, c, MOD - 1), MOD) << "\n";
	}
	return 0;
}