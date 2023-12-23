#include <bits/stdc++.h>

using namespace std;

int const N = 2e6 + 1;
int const MOD = 1e9 + 7;
int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int fct[N], inv[N];
void init(){
	fct[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		fct[i] = 1LL * fct[i - 1] * i % MOD;
		inv[i] = mpow(fct[i], MOD - 2);
	}
}

int C(int k, int n){
	if (k > n) return 0;
	return 1LL * fct[n] * inv[k] % MOD * 1LL * inv[n - k] % MOD;
}

int main(){
	init();
	int n; cin >> n;

	if (n & 1){
		cout << 0;
		return 0;
	}

	string s; cin >> s;
	int a = 0, b = 0;
	int del = 0;
	for (auto x: s){
		if (x == '(') a++, del++;
		else b++, del--;
		if (del < 0){
			cout << 0;
			return 0;
		}
	}	

	a = n / 2 - a;
	b = n / 2 - b;

	cout << (C(a, a + b) - C(b + 1, a + b) + MOD) % MOD;
	return 0;
}