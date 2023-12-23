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
ll tree[N];
void upd(int k, int x){
	for (int i = k; i < N; i += i & -i) tree[i] += x;
}
ll get(int x){
	ll ans = 0;
	for (int i = x; i > 0; i -= i & -i) ans += tree[i];
	return ans;
}

void solve(){
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		upd(i, x);
	}
	
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int p, x; cin >> p >> x;
			upd(p, x);
		}else{
			int l, r; cin >> l >> r;
			cout << get(r) - get(l - 1) << "\n";
		}
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