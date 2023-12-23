#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

int n, q;
ll arr[N];

#define file "f"

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	freopen(file".ans", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	while (q--){
		int t; cin >> t;
		if (t == 2){
			int l, r; cin >> l >> r;
			ll ans = 0;
			for (int i = l; i <= r; i++)
				ans += arr[i] * arr[i];
			cout << ans << "\n";
		}
		if (t == 1){
			int l, r, v; cin >> l >> r >> v;
			for (int i = l; i <= r; i++)
				arr[i] += v;
		}
		if (t == 0){
			int l, r, v; cin >> l >> r >> v;
			for (int i = l; i <= r; i++)
				arr[i] = v;
		}
	}
	return 0;
}