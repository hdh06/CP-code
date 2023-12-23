#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 5e6 + 1;

bool sang[N] = {1, 1};
int fx[N];
void init(){
	for (int i = 0; i < N; i++) fx[i] = i;
	for (ll i = 2; i < N; i++) if (!sang[i])
		for (ll j = i; j < N; j += i) {
			sang[j] = true;
			while (fx[j] % (i * i) == 0) fx[j] /= i * i;
		}
}

int f(int x){return fx[x];};

// int f(int x){
// 	int ans = 1, dem;
// 	for (int i = 2; i <= sqrt(x); i++){
// 		dem = 0;
// 		while (x % i == 0) dem++, x /= i;
// 		if (dem & 1) ans *= i;
// 	}
// 	if (x > 0) ans *= x;
// 	return ans;
// }

int main(){
	init();
	int n; cin >> n;

	int cnt[N] = {};
	for (int i = 1; i <= n; i++) cnt[f(i)]++;

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
	
	cout << ans;
	return 0;
}