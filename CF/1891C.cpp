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
	int n; cin >> n;
	vi arr(n);
	for (auto &x: arr) cin >> x;
	sort(all(arr));
	// debug(arr);
	ll ans = 0;
	ll x = 0;
	for (int i = 0, j = n - 1; i <= j; ){
		// debug(i, j, x, arr[i], arr[j], ans);
		if (i < j){
			if (x + arr[i] >= arr[j]){
				arr[i] -= arr[j] - x;
				ans += 1 + arr[j] - x;
				j--;
				// if (arr[i] == 0) i++;
				x = 0;
			}else{
				x += arr[i];
				ans += arr[i];
				i++;
			}
		}else{
			ans += max(0LL, (arr[i] + x + 1) / 2 - x) + ((arr[i] + x) / 2 > 0);
			i++, j--;
		}
	}
	cout << ans << "\n";
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