#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9;

int const N = 1e6 + 1;

long long mpow(long long x, long long n){
	if (n == 0) return 1 % MOD;

	long long ans = mpow(x, n/ 2);
	ans = (ans*ans) % MOD;

	if (n % 2 == 1) ans = (ans*x%MOD)%MOD;

	return ans;
}

int main(){
	int n, k;
	cin >> n >> k;
	int p = mpow(2, n - 2), tong = 0;
	for (int i = 1; i <= k; i++){
		tong += max(1,p);
		tong %=MOD;
		p /= 2%MOD;
		p %= MOD;
	}
d
	cout << (tong*2%MOD)%MOD;
	return 0;
}