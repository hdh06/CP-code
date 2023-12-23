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

bool const SINGLE_TEST = 1;

void solve(){	
	string a, b; cin >> a >> b;
	reverse(all(b));
	if (sz(a) < sz(b)) a = string(sz(b) - sz(a), '0') + a;
	else b = string(sz(a) - sz(b), '0') + b;
	
	int du = 0;
	vi ans;
	for (int i = sz(a) - 1; i >= 0; i--){
		du += (a[i] - '0') + (b[i] - '0');
		ans.pb(du % 10);
		du /= 10;
	}
	if (du) ans.pb(du);
	reverse(all(ans));
	while (ans.size() > 1 && ans.front() == 0) ans.erase(ans.begin());
	for (auto x: ans) cout << x;		
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