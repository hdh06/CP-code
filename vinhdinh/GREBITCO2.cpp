#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, k; cin >> n >> k;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	ll maxn = arr[1] + k, ans = 0;

	for (int i = 2; i <= n; i++){
		ans = max(ans, maxn - (ll)arr[i] - 1LL*i*k);
		maxn = max(maxn, (ll)arr[i] + 1LL*i*k);
	}

	cout << ans;
	return 0;
}