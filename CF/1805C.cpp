#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "fiel"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

bool const SINGLE_TEST = 0;

void solve(){	
	int n, m; cin >> n >> m;
	
	vl arr(n);
	
	for (auto &x: arr) cin >> x;

	sort(all(arr));
	
	while (m--){
		ll a, b, c; cin >> a >> b >> c;
		int k = lb(all(arr), b) - arr.begin();
		ll ans;
		if (0 < k && k < n){
			if (arr[k] - b <= b - arr[k - 1])
				ans = arr[k];
			else ans = arr[k - 1];
		}else if (k == 0)
			ans = arr[k];
		else if (k == n)
			ans = arr[k - 1];
		
		if ((b - ans) * (b - ans) - 4LL * a * c < 0)
			cout << "YES\n" << ans << "\n";
		else
			cout << "NO\n";
		
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
}//khong phai _HDH, _HDH ko xai template!!!