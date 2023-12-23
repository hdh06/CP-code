#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 2;

typedef long long ll;

vector<ll> g[N];
ll arr[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("test07.inp", "r", stdin);
	// freopen("sol.out", "w", stdout);
	int n, q; cin >> n >> q;	

	for (int i = 1; i <= n; i++)
		g[i].resize(n / i + 2, 0);
	while (q--){
		int l, r, k, x; cin >> l >> r >> k >> x;
		l = (l + k - 1) / k;
		r = (r - r % k) / k;
		if (l > r) continue;
		g[k][l] += x;
		g[k][r + 1] -= x;
	}

	for (int i = 1; i <= n; i++){
		ll x = 0;
		for (int j = 1; j <= n / i; j++){
			x += g[i][j];
			arr[j * i] += x;
		}
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	return 0;
}