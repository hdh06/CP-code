#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 6e4 + 1;

ll tree[N] = {};
int n;

ll get(int i){
	ll tong = 0;
	for (;i < N; i += i&(-i)) tong += tree[i];
	return tong;
}

void upd(int i){
	for (;i >= 1; i -= i&(-i)) tree[i]++;
}

int main(){
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ll t; cin >> t;
		ans += get(t + 1);
		upd(t);
	}

	cout << ans;
	return 0;
}