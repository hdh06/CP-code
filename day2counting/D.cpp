#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int const N = 1e5 + 1;
int fact[N], inv[N];

void init(){
	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}
}

int C(int k, int n){
	if (k > n) return 0;
	return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main(){
	init();
	int n, k, d; cin >> n >> k >> d;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;
	sort(arr.begin(), arr.end());
	
	int ans = 0;
	for (int i = 0, j = 0; j < n; j++){
		while (arr[j] - arr[i] > d) i++;
		(ans += C(k - 1, j - i)) %= MOD;
	}
	cout << ans;
	return 0;
}