#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1010
#endif

using namespace std;

int const N = 5e5 + 1;

typedef long long ll;
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;
	vector<pair<ll, ll> > arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i].st >> arr[i].nd;
	
	sort(arr.begin() + 1, arr.end());
	
	ll pre[N] = {};
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + arr[i].nd;
	
	ll minn = -arr[1].st;
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, pre[i] - arr[i].st - minn);
		minn = min(minn, pre[i] - arr[i + 1].st);
	}
	cout << ans << "\n";
	return 0;
}