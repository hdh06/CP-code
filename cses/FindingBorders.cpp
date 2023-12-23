#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll const R = 123567, MOD = 123123122, N = 1e6 + 1;

int main(){
	string s; cin >> s;

	ll h[N] = {s[0]};

	int n = s.size();

	for (int i = 1; i < n; i++){ 
		h[i] = (h[i - 1]*R + s[i]) % MOD;
	}

	ll P = 1;

	for (int i = 1; i < n; i++){
		P = (P*R)%MOD;
		ll suff = (h[n - 1] - (h[n - 1 - i]*P) % MOD + MOD) %MOD;
		// cout << suff << " ";
		if (h[i - 1] == suff) cout << i << " ";
	}
	return 0;
}