#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int, 2> P;

int const N = 2e6 + 1;
ll const MOD = 1e9 + 7;
int const M = 1002;

ll fact[N];
ll inv[N];

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n & 1) return ans * ans % MOD * x % MOD;
	return ans * ans % MOD;
}

void init(){
	fact[0] = inv[0] = 1;
	for (ll i = 1; i < N; i++){
		fact[i] = fact[i - 1]*i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

ll ways(P A, P B){
	return fact[B[0] - A[0] + B[1] - A[1]]*inv[B[0] - A[0]] % MOD *inv[B[1] - A[1]] % MOD;
	// return fact[B[0] - A[0] + B[1] - A[1]] * mpow(fact[B[0] - A[0]]*fact[B[1] - A[1]] % MOD, MOD - 2) % MOD; 
}

int main(){
	init();
	int n, m; cin >> n >> m;	
	vector<P> arr(m);
	for (auto &x: arr) cin >> x[0] >> x[1];

	arr.push_back({n, n});
	sort(arr.begin(), arr.end());

	ll dp[M] = {};

	for (int i = 0; i <= m; i++){
		dp[i] = ways({1, 1}, arr[i]);
		for (int j = i - 1; j >= 0; j--) if (arr[j][1] <= arr[i][1])
			dp[i] = (dp[i] - dp[j]*ways(arr[j], arr[i]) % MOD + MOD) % MOD; 
	}
	cout << dp[m];
	return 0;
}