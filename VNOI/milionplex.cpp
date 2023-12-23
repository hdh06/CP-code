#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int main(){
	string s; cin >> s;
	long long sum = 0, sum_p = 0, ans = 0;
	for (int i = 0; i < s.size(); i++){
		int d = s[i] - '0';
		sum_p = ((sum_p * 100 % MOD + sum * 20 % MOD * d % MOD) % MOD + d * d % MOD * (i + 1) % MOD) % MOD;
		(ans += sum_p) %= MOD;
		sum = (sum * 10 % MOD + d * (i + 1) % MOD) % MOD;
	}
	cout << ans;
	return 0;
}

// (a * 10 + b) ^ 2 = a ^ 2 * 100 + 20 * b * a + b ^ 2