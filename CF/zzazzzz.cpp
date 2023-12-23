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
#define file "f"

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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	s = ' ' + s;
	vi l(k + 1), r(k + 1);
	for (int i = 1; i <= k; i++) cin >> l[i];
	for (int i = 1; i <= k; i++) cin >> r[i];
	
	int q; cin >> q;
	vi z(q + 1);
	for (int i = 1; i <= q; i++) cin >> z[i];

	
	sort(1 + all(z));

	int idx = 1;
	for (int i = 1; i <= q; i++){
		while (z[i] > r[idx]) idx++;
		if (l[idx] + r[idx] - z[i] < z[i]) z[i] = l[idx] + r[idx] - z[i];
		reverse(s.begin() + z[i], s.begin() + l[idx] + r[idx] - z[i] + 1);
	}
	
	s.erase(0, 1);
	cout << s << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".ans", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!