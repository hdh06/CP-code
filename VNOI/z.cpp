#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#endif
#define ft front
#define bk back
#define st first
#define nd second
#define ins insert
#define ers erase
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define lb lower_bound
#define ub upper_bound
#define mtp make_tuple
#define bg begin
#define ed end
#define all(x) x.bg(), x.ed()
#define sz(x) (int)x.size()
#define int long long
typedef long long ll; typedef unsigned long long ull;
typedef double db; typedef long double ldb;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef vector<int> vi; typedef vector<ll> vll; typedef vector<pi> vpi; typedef vector<pll> vpll;
typedef string str;
template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define FOR(i, l, r) for (int i = l; i <= r; ++i)
#define FOS(i, r, l) for (int i = r; i >= l; --i)
#define FRN(i, n) for (int i = 0; i < n; ++i)
#define FSN(i, n) for (int i = n - 1; i >= 0; --i)
#define EACH(i, x) for (auto &i : x)
#define WHILE while
#define file "TEST"
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
/*
----------------------------------------------------------------
    END OF TEMPLATE
----------------------------------------------------------------
    Tran The Bao - ghostwriter
    Training for VOI23 gold medal
----------------------------------------------------------------
    GOAT
----------------------------------------------------------------
*/
const ll oo = 1e18;
const int N = 1e6 + 5;
const int K = 25;
int n, m, k, c[K], x[K], y[K], w[K], h[K];
ll cnt = 0, minn = oo, maxx = -oo;
vi s[N], e[N];
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    cin >> n >> m >> k;
    FOR(i, 1, k) {
    	cin >> x[i] >> y[i] >> w[i] >> h[i];
    	w[i] += x[i];
    	h[i] += y[i];
    	s[x[i]].pb(i);
    	e[w[i]].pb(i);
    }
    FOR(i, 0, n) {
    	EACH(j, s[i]) c[j] = 1;
    	vpi a;
    	a.pb({0, m});
    	FOR(j, 1, k) {
    		if (!c[j]) continue;
    		vpi a1;
    		EACH(z, a) {
    			int l = z.st, r = z.nd;
    			if (y[j] <= l && h[j] < r && h[j] >= l) {
    				a1.pb({l, h[j]});
    				a1.pb({h[j] + 1, r});
    			}
    			else if (y[j] > l && y[j] <= r && h[j] >= r) {
    				a1.pb({l, y[j] - 1});
    				a1.pb({y[j], r});
    			}
    			else if (y[j] > l && h[j] < r) {
    				a1.pb({l, y[j] - 1});
    				a1.pb({y[j], h[j]});
    				a1.pb({h[j] + 1, r});
    			}
    			else a1.pb({l, r});
    		}
    		a = a1;
    	}
    	EACH(j, a) {
    		int l = j.st, r = j.nd, c1 = 0;
    		FOR(z, 1, k) {
    			if (!c[z]) continue;
    			if (h[z] < r || y[z] > l) continue;
    			c1 ^= 1;
    		}
    		if (c1) {
    			cnt += r - l + 1;
    			minn = min(minn, i + 1LL * l * (n + 1));
    			maxx = max(maxx, i + 1LL * r * (n + 1));
    		}
    	}
    	EACH(j, e[i]) c[j] = 0;
    }
    cout << cnt << ' ' << (minn < oo? minn : -1) << ' ' << (maxx > -oo? maxx : -1);
    return 0;
}
/*
2 3 2
0 0 0 0
2 3 0 0
----------------------------------------------------------------
From Benq:
    stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
----------------------------------------------------------------
*/