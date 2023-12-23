#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#endif
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define lb lower_bound
#define ub upper_bound
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define ull unsigned long long
#define ldb long double
#define db double
#define str string
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define gcd __gcd
#define lcm(a, b) ((a) / gcd((a), (b)) * (b))
#define FOR(i, l, r) for (int (i) = (l); (i) <= (r); ++(i))
#define FOS(i, r, l) for (int (i) = (r); (i) >= (l); --(i))
#define EACH(i, x) for (auto &(i) : (x))
#define WHILE while
#define file "TEST"
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
/*
    Tran The Bao
    CTL - Da Lat
    Practising for VOI23 gold medal
*/
const int N = 5001;
int n, d[N];
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    cin >> n;
    d[0] = 0;
    FOR(i, 1, n) {
        d[i] = i;
        FOR(j, 1, i - 1)
            d[i] ^= d[j];
    }
    FOR(i, 1, n) {
        cerr << i << " : " << (i ^ (i - 1)) << '\n';
    }
    return 0;
}