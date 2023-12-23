#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

typedef long long ll;

int main(){
	int n; cin >> n;
	ll ps[N];
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		ps[i] = ps[i - 1] + x;
	}

	int l = 0, r = 0;
	ll ans = 0;
	set<ll> s = {0};
	while (l <= n){
		while (r < n && s.count(ps[r + 1]) == 0){
			r++;
			s.insert(ps[r]);
		}
		ans += r - l;
		s.erase(ps[l]);
		l++;
	}
	cout << ans;
	return 0;
}