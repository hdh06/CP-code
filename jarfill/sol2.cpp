#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 2;
int const M = 6638451;
typedef long long ll;
int f[N];
ll g[M], arr[N];

int main(){ 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("test07.inp", "r", stdin);
	freopen("sol.out", "w", stdout);
	int n, q; cin >> n >> q;	
	int cnt = 0;
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] + n / i;
	while (q--){
		int l, r, k, x; cin >> l >> r >> k >> x;
		l = (l + k - 1) / k;
		r = (r - r % k) / k;
		if (l > r) continue;
		g[f[k - 1] + l] += x;
		if (r + 1 <= n / k) g[f[k - 1] + r] -= x;
	}

	for (int i = 1; i <= n; i++){
		ll x = 0;
		for (int j = 1; j <= n / i; j++){
			x += g[f[i - 1] + j];
			arr[j * i] += x;
		}
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	return 0;
}