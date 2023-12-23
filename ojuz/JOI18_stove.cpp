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

bool const SINGLE_TEST = 1;

int const N = 1e5 + 1;

void solve(){
	int n, k; cin >> n >> k;
	
	int arr[N] = {};
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	multiset<int> s;
	for (int i = 2; i <= n; i++){
		s.insert(arr[i] - arr[i - 1] - 1);
		if (s.size() > k - 1) s.erase(s.begin());
	}
	
	ll ans = arr[n] + 1 - arr[1];
	for (auto x: s)
		ans -= x;
	cout << ans;
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