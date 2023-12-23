#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#endif

using namespace std;

int const N = 1e4 + 5;
int const P = 1e2 + 1;
int const K = 5;
int const MOD = 1e9 + 7;

int t, p, k;

string L, R;

int dp[N][2][P][1 << K];
int calc(int i, bool ok, bool isl, int rmd, int mask, string &R){
	if (i == R.size())
		return rmd == 0 && !isl;
	
	int &ans = dp[i][isl][rmd][mask];
	if (!ok && ans != -1) return ans;
	
	int res = 0;
	
	for (int d = 0; d <= (ok? R[i] - '0': 9); d++){
		if (mask & (1 << ((k - d % k) % k)) ) continue;
		(res += calc(i + 1,	ok & (d == R[i] - '0'),	isl & (d == 0), (rmd * (10 % p) % p + (d % p)) % p, ((isl & (d == 0))? mask: mask | (1 << (d % k))), R) ) %= MOD;
	}
	
	return !ok? ans = res: res;
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> t >> p >> k;
	
	memset(dp, -1, sizeof dp);
	while (t--){
		cin >> L >> R;
		
		int pos = L.size() - 1;
		while (L[pos] == '0') L[pos] = '9', pos--;
		L[pos]--;
		
		L = string(N - L.size(), '0') + L;
		R = string(N - R.size(), '0') + R;
		cout << (calc(0, 1, 1, 0, 0, R) - calc(0, 1, 1, 0, 0, L) + MOD) % MOD << "\n";	
	}
	return 0;
}