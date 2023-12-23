#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e5 + 1;

ll arr[N];

void solve(){
	int n, x; cin >> n >> x;	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	ll maxx = 0, minn = LLONG_MAX, ans = 0;
	for (int i = 1; i <= n; i++){
		maxx = max(maxx, arr[i]);
		minn = min(minn, arr[i]);
		if (maxx - minn > 2 * x){
			maxx = arr[i];
			minn = arr[i];
			ans++;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}