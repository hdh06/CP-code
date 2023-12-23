#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll n; cin >> n;

	vector<int> div;
	for (int i = 1; i <= sqrt(n); i++) if (n % i == 0){
		div.push_back(i);
		if (n / i != i) div.push_back(n / i);
	}

	int sz = div.size();

	unordered_map<int, int> cnt;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			if (div[i] % div[j] == 0) cnt[div[i]]++;

	ll ans = 0;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++) if (n >= 1LL * div[i] * div[j])
			if (n % (div[i] * div[j]) == 0)
				ans += cnt[n / (1LL * div[i] * div[j])];
		
	cout << ans << "\n";
}

int main(){
	// freopen("fourking.inp", "r", stdin);
	// freopen("fourking.out", "w", stdout);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}