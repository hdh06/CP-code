#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const MOD = 1e9 + 7;
int const P = 2001;
int const N = 1e5 + 1;

ll mpow(ll x, ll n){
	if (n == 0) return 1;
	ll ans = mpow(x, n / 2);
	if (n&1) return ans*ans%MOD * x %MOD;
	return ans*ans % MOD;
}

ll fact[N] = {};

void init(){
	fact[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = fact[i - 1]*i % MOD;
	}
}

ll C(ll k, ll n){
	return fact[n]*mpow(fact[k]*fact[n - k] % MOD) %MOD;
}

int main(){
	int n, m; cin >> n >> m;
	int p; cin >> p;
	array<int, 2> arr[P];
	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];
	arr.push_back({n, m});

	sort(arr + 1, arr + n + 1);

	ll dp[P];

	for (int i = 1; i <= n; i++){
		dp[i] = C(arr[i][0] - 1, arr[i][0] + arr[i][1] - 2);
		for (int j = i - 1; j >= 1; j--) if (arr[j][1] <= arr[i][1] && arr[j][0] <= arr[i][0]){
			dp[i] -= dp[j]*C(arr[i][0] - arr[j][0], arr[i][0] - arr[j][0] + arr[i][1] - arr[j][1]) %MOD;
			dp[i] %= MOD;
		}
	}
	cout << dp[p];
	return 0;	
}