#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const MOD = 1e9 + 7;

int main(){
	int n, k; cin >> n >> k;
	if (k > n - k) k = n - k;
	
	int mau = 1, tu = 1;
	for (int i = n - k + 1; i <= n; ++i)
		mau = 1LL * mau * i % MOD,
		tu = 1LL * tu * (n - i + 1) % MOD;
		
	n = MOD - 2;
	int ans = 1;
	while (n){
		if (n & 1) ans = 1LL * ans * tu % MOD;
		tu = 1LL * tu * tu % MOD;
		n >>= 1;
	}
	
	cout << 1LL * mau * ans % MOD;
	return 0;
}//it's coding time!