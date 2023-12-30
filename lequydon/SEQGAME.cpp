#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1000
#endif

using namespace std;

typedef long long ll;

int const N = 3e5 + 1;

int n;
int a[N], b[N], c[N];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	ll ans = LLONG_MIN, minn = a[1], maxx = a[1];
	ll pre_max = max(1LL * a[1] * b[1], 1LL * a[1] * b[2]), pre_min = min(1LL * a[1] * b[1], 1LL * a[1] * b[2]);
	for (int i = 3; i <= n; i++){
		ans = max(ans, max(pre_max * c[i], pre_min * c[i]));
		
		// debug(pre_max, pre_min);
		
		pre_max = max(pre_max, max(maxx * b[i], minn * b[i]));
		pre_min = min(pre_min, min(minn * b[i], maxx * b[i]));
		
		
		minn = min(minn, 1LL * a[i]);
		maxx = max(maxx, 1LL * a[i]);
	}
	
	cout << ans;
	return 0;
}//khong phai code cua Huy 100% la the