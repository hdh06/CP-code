#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

void solve(){
	int n; cin >> n;
	vl arr(n);
	for (auto &x: arr) cin >> x;
	
	if (n & 1){
		ll ans = 0;
		for (int i = 1; i < n - 1; i += 2){
			ll del = max(arr[i + 1], arr[i - 1]) + 1;
			ans += max(0LL, del - arr[i]);
		}
		cout << ans << "\n";
	}else{
		vl pre(n), suf(n);
		for (int i = 1; i < n - 1; i += 2){
			ll del = max(arr[i + 1], arr[i - 1]) + 1;
			pre[i] = pre[i - 1] + max(0LL, del - arr[i]);
			pre[i + 1] = pre[i];
		}
		for (int i = n - 2; i >= 1; i -= 2){
			ll del = max(arr[i + 1], arr[i - 1]) + 1;
			suf[i] = suf[i + 1] + max(0LL, del - arr[i]);
			suf[i - 1] = suf[i];
		}
		ll ans = min(pre[n - 2], suf[1]);
		for (int i = 1; i < n - 1; i += 2)
			ans = min(ans, pre[i] + suf[i + 2]);
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!