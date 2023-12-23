#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int mob(int x){
	int ans = 0;
	for (int i = 2; i <= sqrt(x); i++){
		int dem = 0;
		ans += (x % i == 0);
		while (x % i == 0) dem++, x /= i;
		if (dem > 1) return 0;
	}
	if (x > 0) ans++;
	return (ans & 1? 1: -1);
}

int main(){
	int n; cin >> n;
	int cnt[N] = {};
	for (int i = 1; i <= n; i++){
		int t; cin >> t; cnt[t]++;
	}

	for (int i = 2; i < N; i++)
		for (int j = 2 * i; j < N; j += i)
			cnt[i] += cnt[j];

	for (int i = 2; i < N; i++)
		cnt[i] = (mpow(2, cnt[i]) - 1 + MOD) % MOD;

	int ans = 0;
	for (int i = 2; i < N; i++)
		ans = (ans + 1LL * mob(i) * cnt[i] + MOD) % MOD;
	cout << ((mpow(2, n) - ans + MOD) % MOD - 1 + MOD) % MOD;
	return 0;
}