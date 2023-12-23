#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;

	ll cnt[N] = {1};
	ll ans = 0, sum = 0;
	int x;
	for (int i = 1; i <= n; i++){
		cin >> x;
		(sum = sum + x + 1LL * 10000 * n) %= n;
		ans += cnt[sum];
		cnt[sum]++;
	}
	cout << ans;
	return 0;
}