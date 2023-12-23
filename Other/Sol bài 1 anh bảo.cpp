#define int long long
const int oo = 1e17;
const int N = 405;
int n, l;
int a[N], c[N];
//pll d[N][N][N][N];
ll s = 0, sa = 0;
ll d1[105][105][N + 100];
pll ANS = {1e17, 1};
ll DP(int i, int l, int A) {
    if (l < 0 || A < 0)
        return oo;
    if (i > n) {
        if (l == 0 && A == 0)
            return 0;
        return oo;
    }
    int &rs = d1[i][l][A];
    if (rs != oo)
        return rs;
    rs = 0;
    rs = min(DP(i + 1, l, A), DP(i + 1, l - 1, A - ::a[i]) + c[i]);
//    cerr << i << ' ' << l << ' ' << A << " : " << rs << '\n';
    return rs;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], sa += a[i];
    for (int i = 1; i <= n; ++i)
        cin >> c[i], s += c[i];
    // if (n <= 50) {
        // cout << setprecision(3) << fixed << (ldb)dp(1, l, 0, 0).st / (ldb)dp(1, l, 0, 0).nd;
        // return 0;
    // }
    for (int i = 0; i <= 100; ++i)
    for (int j = 0; j <= 100; ++j)
    for (int z = 0; z <= 500; ++z)
        d1[i][j][z] = oo;
    for (int i = 1; i <= sa; ++i) {
        ll TMP = DP(1, l, i);
        if (TMP == oo)
            continue;
        ANS = MAXX(ANS, {TMP * (s - TMP), i * (sa - i)});
    }
//    cerr << ANS.st << ' ' << ANS.nd << '\n';
    cout << setprecision(3) << fixed << (ldb)ANS.st / (ldb)ANS.nd;
    return 0;
}