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
#define file "inp"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

int const N = 1001;

ll tree[N][N];
void upd(ll x, ll y){
	for (int i = x; i < N; i += i & -i)
		for (int j = y; j < N; j += j & -j)
			tree[i][j] += x * y;
}
ll get(ll x, ll y){
	ll ans = 0;
	for (int i = x; i > 0; i -= i & -i)
		for (int j = y; j > 0; j -= j & -j)
			ans += tree[i][j];
	return ans;
}

void init(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tree[i][j] = 0; 
}

void solve(){
	int n, q; cin >> n >> q;
	init();
	for (int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		upd(x, y);
	}
	
	while (q--){
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;
		cout << get(hb - 1, wb - 1) - get(hs, wb - 1) - get(hb - 1, ws) + get(hs, ws) << "\n";
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