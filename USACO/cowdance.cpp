#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, t;
int d[N];

typedef long long ll;

int f(int k){
	multiset<int> s;

	for (int i = 1; i <= k; i++)
		s.insert(d[i]);

	for (int i = k + 1; i <= n; i++){
		int x = *s.begin();
		s.erase(s.begin());
		s.insert(x + d[i]);
	}

	return *(s.rbegin());
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> d[i];

	ll ans = 0;

	for (int l = 1, r = 1e5; l <= r;){
		int mid = (l + r) >> 1;
		if (f(mid) <= t){
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}

	cout << ans;
	return 0;
}