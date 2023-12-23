#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
} 

int main(){	
	long long n, m; cin >> n >> m;
	n--, m--;
	n %= MOD, m %= MOD;
	cout << mpow(1e6 + 3, 1LL * m * n % (MOD - 1));	
	return 0;
}