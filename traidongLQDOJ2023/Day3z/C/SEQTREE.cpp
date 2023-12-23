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
#define file "SEQTREE"

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

int const N = 2e5 + 1;

int n, q, t;
ll arr[N];

ll hi(ll x){
	ll h = 0;
	while (x > 0){
		h++;
		x -= h;
	}
	return h;
}

ll jump(ll x){
	if (x == 1) return 1;
	ll h = hi(x);
	// debug(h);
	ll pos = x - h * (h - 1) / 2;
	h--;
	ll s = arr[h] - h * (h - 1) / 2;
	if (pos <= s) return pos + h * (h - 1) / 2;
	return pos - 1 + h * (h - 1) / 2;
}

namespace sub2{
	void solve(){
		// debug(jump(9));
		ll preans = 0;
		while (q--){
			ll x, y; cin >> x >> y;
			x = (x - 1 + t * preans) % (1LL * (n + 1) * (n + 2) / 2) + 1;
			y = (y - 1 + t * preans) % (1LL * (n + 1) * (n + 2) / 2) + 1;

			if (hi(x) > hi(y)) swap(x, y);
			while (hi(x) < hi(y)) y = jump(y);
			while (x != y) x = jump(x), y = jump(y);
			preans = x;
			cout << preans << "\n";
		}	
	}
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n >> q >> t;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	// if (n <= 2000)
		sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!