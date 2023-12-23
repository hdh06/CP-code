#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const MOD = 1e9 + 7;
int const N = 1e6 + 1;

int main(){
	int n, k; cin >> n >> k;	
	ll fsum[N] = {0, 1};
	ll dp[N] = {0, 1};

	vector<array<int, 2> > arr(k);
	for (auto &x: arr) cin >> x[0] >> x[1];

	for (int i = 2; i <= n; i++){
		for (auto x: arr){
			int l = max(0, i - x[0]), r = max(0, i - x[1] - 1);
			(dp[i] += fsum[l] - fsum[r] + MOD) %= MOD;
		}
		fsum[i] = (fsum[i - 1] + dp[i]) % MOD;
	}
	cout << dp[n];
	return 0;
}