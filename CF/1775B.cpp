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

int const N = 2e5 + 1;

map<int, int> cnt;

vi g[N];

void solve(){
	cnt.clear();
	int n; cin >> n;
	for (int i = 1; i <= n; i++) g[i].clear();
	
	for (int i = 1; i <= n; i++){
		int k; cin >> k;
		for (int j = 1; j <= k; j++){
			int x; cin >> x;
			g[i].pb(x);
		}
	}
	
	sort(g + 1, g + n + 1, [](vi a, vi b){
		return a.size() > b.size();
	});
	
	bool ans = 0;
	for (int i = 1; i <= n; i++){
		bool is = 1;
		for (auto x: g[i]){
			if (cnt[x] == 0) is = 0;
			cnt[x]++;
		}
		ans |= is;
	}
	cout << (ans? "Yes\n": "No\n");
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