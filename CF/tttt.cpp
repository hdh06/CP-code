//Tran Trung Hieu - 11 Tin - CTL - Da Lat
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef array<int, 3> pii;
typedef array<ll, 3> plll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<plll> vplll;
typedef vector<vi> vvi;
template<typename T> T sqr(T a) { return a * a; }
template<typename T> T gcd(T a, T b) { return (b == 0)? a : gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define FOR(i, l, r) for (int i = l; i <= r; ++i)
#define FOS(i, r, l) for (int i = r; i >= l; --i)
#define FR1(i, n) FOR(i, 1, n)
#define FS1(i, n) FOS(i, n, 1)
#define FR0(i, n) FOR(i, 0, n - 1)
#define FS0(i, n) FOS(i, n - 1, 0)
#define EACH(i, x) for (auto &i : x)
#define WHILE while
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define lb lower_bound
#define ub upper_bound
// #define cout cerr
// #define int ll
#define FILE "digit2"
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
const int N = 1e4 + 1;
const int M = 1e2 + 1;
const int mod = 1e9 + 7;
int x, y, d[N][M][32];
str l, r;
int dp(int i, int j, int mask) {
	if (i == N - 1) return mask && j == 0;
	int &rs = d[i][j][mask];
	if (rs != -1) return rs;
	rs = 0;
	FR0(k, 10) {
		int kk = (y - k % y) % y;
		if (mask >> kk & 1) continue;
		int nmask;
		if (!mask && !k) nmask = 0;
		else nmask = mask | (1 << k % y);
		(rs += dp(i + 1, (j * 10 + k) % x, nmask)) %= mod;
	}
	// cerr << i << ' ' << j << ' ' << mask << ": " << rs << '\n';
	return rs;
}
int calc(str &s) {
	int j = 0, mask = 0, rs = 0;
	FOR(i, N - sz(s), N - 1) {
		int pos = i - N + sz(s);
		// cerr << i << ": " << j << ' ' << mask << '\n';
		FR0(val, s[pos] - '0') {
			int kk = (y - val % y) % y;
			if (mask >> kk & 1) continue;
			int nmask;
			if (!mask && !val) nmask = 0;
			else nmask = mask | (1 << val % y);
			(rs += dp(i, (j * 10 + val) % x, nmask)) %= mod;
		}
		j = (j * 10 + (s[pos] - '0')) % x;
		int kk = (y - (s[pos] - '0') % y) % y;
		if (mask >> kk & 1) return rs;
		else if (!mask && !(s[pos] - '0')) mask = 0;
		else mask = mask | (1 << (s[pos] - '0') % y);
	}
	// cerr << N - 1 << ' ' << j << ' ' << mask << ": " << dp(N - 1, j, mask) << '\n';
	(rs += dp(N - 1, j, mask)) %= mod;
	// cerr << s << ": " << rs << '\n';
	return rs;
}
void solve() {
    cin >> l >> r;
    FS0(i, sz(l)) {
		if (l[i] == '0') l[i] = '9';
		else {
			--l[i];
			break;
		}
    }
    WHILE(sz(l) < sz(r)) l = '0' + l;
    // calc(l);
    cerr << calc(r) << " " << calc(l) << "\n";
    cout << (calc(r) - calc(l) + mod) % mod << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(FILE".inp", "r", stdin);
    // freopen(FILE".out", "w", stdout);
    memset(d, -1, sizeof d);
    int t = 1;
    cin >> t >> x >> y;
    WHILE (t--) {
        solve();
    }
    return 0;
}
/*

*/