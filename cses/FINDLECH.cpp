#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 3;

int main(){
	int n, q; cin >> n >> q;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	ll psum[N] = {}, ssum[N] = {};
	for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + arr[i];
	for (int i = n; i >= 1; i--) ssum[i] = ssum[i + 1] + arr[i];
		
	int mpos = 1;

	for (int i = 1; i <= n; i++)
		if (abs(psum[mpos] - ssum[mpos + 1]) > abs(psum[i] - ssum[i + 1]))
			mpos = i;
		
	while (q--){
		int l, r; cin >> l >> r;
		ll ans = 0;
		if (l <= mpos && mpos <= r){
			ans = (psum[mpos] - psum[l - 1]) - (ssum[mpos + 1] - ssum[r + 1]);
		}	
		else{
			ans = min(psum[l] - psum[l - 1] - ssum[l + 1] + ssum[r + 1], psum[r] - psum[l - 1] - ssum[r + 1] + ssum[r + 1]);
		}
		cout << ans << endl;
	}
	return 0;
}