#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t; cin >> t;
	while (t--){
		int l, r; cin >> l >> r;
		ll ans_l = 0, ans_r = 0;
		l--;
		while (r){
			ans_r += 1LL * ((r + 1) / 2) * ((r + 1) / 2);
			r /= 2;
		}
		while (l){
			ans_l += 1LL * ((l + 1) / 2) * ((l + 1) / 2);
			l /= 2;
		}
		cout << ans_r - ans_l << "\n";
	}
	return 0;
}

//OD(x) = x neu x le
//OD(x) = OD(x / 2) neu x chan
//ODS(x) = tong OD(i) i: 1 -> x = 1 + 3 + 5 + ... + OD(2) + OD(4) + OD(6)
//       = ((n + 1) / 2 ) ^ 2 + ODS(x / 2)