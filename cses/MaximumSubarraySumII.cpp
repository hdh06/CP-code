#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

typedef long long ll;

int main(){
	int n, a, b; cin >> n >> a >> b;
	int arr[N];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	ll ans = LLONG_MIN, psum[N] = {};
	multiset<ll> ms;
	for (int i = 1, l = 0, r = -1; i <= n; i++){
		psum[i] = psum[i - 1] + arr[i];
		while (r < i - a)
			ms.insert(psum[++r]);
		while (l < i - b)
			ms.erase(ms.find(psum[l++]));
		if (!ms.empty()) ans = max(ans, psum[i] - *ms.begin());
	}
	cout << ans;
	return 0;
}