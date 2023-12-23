#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
	ll p, q; cin >> p >> q;

	ll tmp = q;
	vector<int> t;
	for (int i = 2; i <= sqrt(tmp); i++){
		if (tmp % i == 0)
			t.push_back(i);
		while (tmp % i == 0) tmp /= i;
	}
	if (tmp > 1) t.push_back(tmp);
	
	ll ans = 0;
	for (auto x: t){
		tmp = p;
		while (tmp % q == 0) tmp /= x;
		ans = max(ans, tmp);
	}

	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}