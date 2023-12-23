#include <bits/stdc++.h>

using namespace std;

int const N = 630005;
int const MOD = 1019972207;

string s;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int fact[N], inv[N];
void init(){
	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = 1LL * fact[i - 1] * i % MOD,
		inv[i] = mpow(fact[i], MOD - 2);

}

int C(int k, int n){
	if (k < 0 || n < 0) return 0;
	if (k > n) return 0;
	return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main(){
	init();
	cin >> s;
	int n = s.size();
	s = ' ' + s;

	int left[N] = {}, right[N] = {};
	for (int i = 1; i <= n; i++)
		left[i] = left[i - 1] + (s[i] == '(');

	for (int i = n; i >= 1; i--)
		right[i] = right[i + 1] + (s[i] == ')');

	int ans = 0;
	for (int i = 1; i <= n; i++) if (s[i] == '(')
		(ans += C(right[i + 1] - 1, left[i - 1] + right[i + 1])) %= MOD;

	cout << ans;
	return 0;
}
