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
#define file "EZTASK"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 1e6 + 1;

bool sang[N] = {1, 1};
void init(){
	for (ll i = 2; i < N; i++) if (!sang[i])
		for (ll j = i * i; j < N; j += i)
			sang[j] = 1;
}

void solve(){
	int n; cin >> n;
	vi arr;
	ll ans = LLONG_MIN;
	vl psum(n + 1);
	for (int i = 1; i <= n; i++){
		ll x; cin >> x;
		psum[i] = psum[i - 1] + x;
		if (!sang[i]) arr.pb(i), ans = max(ans, x);
	}

	for (int i = 0; i < arr.size(); i++)
		for (int j = i; j < arr.size(); j++)
			ans = max(ans, psum[arr[j]] - psum[arr[i] - 1]);

	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".ans", "w", stdout);
	init();
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!