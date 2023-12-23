#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int mob(int x){
	bool ans = 0;
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0) ans ^= 1;
		int dem = 0;
		while (x % i == 0) x /= i, dem++;
		if (dem > 1) return 0;
	}
	if (x > 1) ans ^= 1;
	return (ans ? 1: -1);
}

typedef long long ll;

int main(){
	int n; cin >> n;
	int cnt[N] = {};
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		for (int j = 1; j * j <= x; j++) if (x % j == 0){
			cnt[j]++;
			if (x / j != j) cnt[x / j]++;
		}
	}

	ll ans = 0;
	for (int i = 2; i < N; i++) if (cnt[i] > 1){
		// cout << i << ": " << mob(i) << " " << cnt[i] << "\n";
		ans += 1LL * mob(i) * cnt[i] * (cnt[i] - 1) / 2;
	}
	
	cout << 1LL * n * (n - 1) / 2 - ans;
	return 0;
}