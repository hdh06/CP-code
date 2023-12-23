#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
#define st first
#define nd second

int n, c, q;

void solve(){
	cin >> n >> c >> q;
	string s; cin >> s;
	vector<ii> arr(c);
	vector<ll> t;
	for (auto &x: arr){
		cin >> x.st >> x.nd;
		x.st--, x.nd--;
	}
	ll curr = s.size();
	for (auto &x: arr){
		t.push_back(curr - x.st);
		ll pre = curr;
		curr += x.nd - x.st + 1;
		x.st = pre, x.nd = curr - 1;
	}
	
	while (q--){
		ll k; cin >> k;
		k--;
		for (int i = c - 1; i >= 0; i--) if (arr[i].st <= k && k <= arr[i].nd)
			k -= t[i];
		cout << s[k] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}