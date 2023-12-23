#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void compress(vector<ll> &arr){
	set<ll> s(arr.begin(), arr.end());
	vector<ll> b(s.begin(), s.end());
	for (auto &x: arr)
		x = lower_bound(b.begin(), b.end(), x) - b.begin();
}

void solve(){
	int n; cin >> n;
	vector<ll> cnt(n), a(n);
	for (auto &x: a) cin >> x;

	compress(a);
	for (auto x: a) cnt[x] ++;

	sort(cnt.begin(), cnt.end());

	vector<ll> ssum(n + 1, 0);
	for (int i = n - 1; i >= 0; i--)
		ssum[i] = ssum[i + 1] + cnt[i];
	
	ll ans = LLONG_MAX;
	ll sum = 0;
	for (int i = 0; i < n; i++){
		ans = min(ans, ssum[i] - cnt[i] * (n - i) + sum);
		sum += cnt[i];
	}

	cout << ans << "\n"; 
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}