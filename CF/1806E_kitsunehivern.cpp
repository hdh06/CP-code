#include <bits/stdc++.h>
/// kitsune
using namespace std;

#define fi first
#define se second
#define mp make_pair
//#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define per(i, r, l) for (int i = (int)(r); i >= (int)(l); i--)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename _Tp> bool minimize(_Tp &__a, const _Tp &__b) { if (__a > __b) { __a = __b; return true; } return false; }
template<typename _Tp> bool maximize(_Tp &__a, const _Tp &__b) { if (__a < __b) { __a = __b; return true; } return false; }

const int siz = 1e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const ll MAXX = 1e18;
const string file = "1";

int a[siz];
vector<int> child_list[siz];
int par[siz], dep[siz];
ll sum[siz];

void dfs(int u, int p) {
    sum[u] = sum[p] + a[u] * (ll)a[u];
    for (auto v : child_list[u]) {
        par[v] = u;
        dep[v] = dep[u] + 1;

        dfs(v, u);
    }
}

map<int, ll> f[siz];

ll query(int u, int v) {
    if (u == v) {
        return sum[u];
    }

    if (u > v) {
        swap(u, v);
    }

    if (f[u].count(v)) {
        return f[u][v];
    }

    return -1;
}

void update(int u, int v, ll val) {
    if (u == v) {
        return;
    }

    if (u > v) {
        swap(u, v);
    }

    f[u][v] = val;
}

ll ans[siz];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen((file + ".inp").c_str(), "r", stdin);
//    freopen((file + ".out").c_str(), "w", stdout);

    int n, q;
    cin >> n >> q;

    rep (u, 1, n) {
        cin >> a[u];
    }

    rep (u, 2, n) {
        int p;
        cin >> p;

        child_list[p].push_back(u);
    }

    dfs(1, 0);

    vector<pair<pii, int>> queries;
    rep (i, 1, q) {
        int u, v;
        cin >> u >> v;

        queries.push_back(mp(mp(u, v), i));
    }

    sort(all(queries), [&](const pair<pii, int>& x, const pair<pii, int>& y) -> bool {
        return dep[x.fi.fi] < dep[y.fi.fi];
    });

    for (auto z : queries) {
        int u = z.fi.fi, v = z.fi.se, i = z.se;
        pii save = mp(u, v);

        ans[i] = 0;
        while (true) {
            ll tmp = query(u, v);
            if (tmp != -1) {
                ans[i] += tmp;
                break;
            }

            ans[i] += a[u] * (ll)a[v];
            update(u, v, ans[i]);
            u = par[u];
            v = par[v];
        }

        update(save.fi, save.se, ans[i]);
    }

    rep (i, 1, q) {
        cout << ans[i] << "\n";
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}