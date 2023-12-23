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

int a[N], b[N];

int tree[N];
void upd(int k, int val){
	for (int i = k; i < N; i += i & -i)
		tree[i] += val;
}
int get(int k){
	int ans = 0;
	for (int i = k; i > 0; i -= i & -i)
		ans += tree[i];
	return ans;
}

void solve(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		upd(i, -get(i));
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	
	for (int i = 1; i <= n; i++) if (a[i] > b[i]){
		upd(b[i], 1);
		upd(a[i], -1);
	}	
	
	vi ans;
	for (int k = 1; k <= n; k++){
		bool is = 1;
		for (int j = k; j <= n; j += k)
			if (get(j) > 0) is = 0;	
		if (is) ans.pb(k);
	}
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " "; cout << "\n";
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