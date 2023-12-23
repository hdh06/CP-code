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

ii beValid(int i, int j){
	return {min(i, j), max(i, j)};
}

void solve(){	
	int n; cin >> n;
	vi pos(n + 1), arr(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	
	vii ans;
	for (int i = 1; i <= n; i++){
		ans.pb({i, pos[i]});
		if (pos[i] - i > 2) ans.pb({i  + 1, pos[i] - 1});
		swap(arr[pos[i]], arr[i]);
		swap(pos[i], pos[arr[pos[i]]]);
	}

	cout << ans.size() << "\n";
	for (auto x: ans) cout << x.st << " " << x.nd << "\n";
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