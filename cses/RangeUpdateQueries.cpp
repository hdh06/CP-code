#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int const N = 2e5 + 2;
ll tree[N];

void upd(int x, int k){
	for (int i = x; i < N; i += (i & -i)) tree[i] += k;
}
ll get(int x){
	ll ans = 0;
	for (int i = x; i > 0; i -= (i & -i)) ans += tree[i];
	return ans;
}

int main(){
	int n, q; cin >> n >> q;
	int arr[N];
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		upd(i, arr[i] - arr[i - 1]);
	}

	while (q--){
		int t; cin >> t;
		if (t == 1){
			int a, b, u; cin >> a >> b >> u;
			upd(a, u); upd(b + 1, -u);
		}
		if (t == 2){
			int k; cin >> k;
			cout << get(k) << "\n";
		}
	}
	return 0;
}