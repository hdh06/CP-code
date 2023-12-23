#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const MOD = 1e9 + 7;
typedef long long ll;

int mpow(int x, ll n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int main(){
	int n; cin >> n;
	
	if (n & 1){
		int x = mpow(2, 1LL * (n / 2) * (n / 2) + n / 2);
		cout << 2LL * ((((x + x) % MOD + mpow(x, 2)) % MOD + mpow(x , 4)) % MOD) % MOD * mpow(4, MOD - 2) % MOD;
	}else{
		int x = mpow(2, 1LL * (n / 2) * (n / 2));
		cout << 1LL * ((((x + x) % MOD + mpow(x, 2)) % MOD + mpow(x, 4)) % MOD) * mpow(4, MOD - 2) % MOD;
	}

	return 0;
}