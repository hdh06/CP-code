#include <bits/stdc++.h>

using namespace std;

#define int long long

int const MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return ans*ans % MOD * x % MOD;
	return ans*ans % MOD;
}

signed main(){
	cout << mpow(2, MOD - 2);
	return 0;
}