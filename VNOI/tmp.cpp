//#define kitsune

#ifdef kitsune
#include "kitsune.h"
using namespace kitsune::debugger;
#endif

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define per(i, r, l) for (int i = (int)(r); i >= (int)(l); i--)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template <typename _Tp> bool minimize(_Tp &__a, const _Tp &__b) { if (__a > __b) { __a = __b; return true; } return false; }
template <typename _Tp> bool maximize(_Tp &__a, const _Tp &__b) { if (__a < __b) { __a = __b; return true; } return false; }

const int siz = 1e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const ll MAXX = 1e18;
const string file = "distance3";

const ld pi = acos(-1);

struct point {
    ld x, y;

    point(ld x = 0, ld y = 0) : x(x), y(y) {
    }
};

struct vectar {
    ld x, y;

    vectar(ld x = 0, ld y = 0) : x(x), y(y) {
    }

    vectar(point A, point B) : x(B.x - A.x), y(B.y - A.y) {
    }

    ld length() {
        return sqrt(x * x + y * y);
    }

    ld operator * (const vectar &oth) const { /// dot product
        return x * oth.x + y * oth.y;
    }

    ld operator ^ (const vectar &oth) const { /// cross product
        return x * oth.y - y * oth.x;
    }
};

struct line {
    ld a, b, c;

    line(ld a = 0, ld b = 0, ld c = 0) : a(a), b(b), c(c) {
    }

    line(point A, point B) {
        vectar u_AB = vectar(A, B), n_AB = vectar(u_AB.y, -u_AB.x);
        a = n_AB.x;
        b = n_AB.y;
        c = n_AB.x * (-A.x) + n_AB.y * (-A.y);
    }
};

ld sqr(ld x) {
    return x * x;
}

ld distance(point A, point B) {
    return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

ld distance(point A, line l) {
    return abs(l.a * A.x + l.b * A.y + l.c) / sqrt(sqr(l.a) + sqr(l.b));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen((file + ".in").c_str(), "r", stdin);
//    freopen((file + ".out").c_str(), "w", stdout);

    point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    vectar u_BA = vectar(B, A), u_BC = vectar(B, C);
    ld ans;
    if (acos((u_BA * u_BC) / (u_BA.length() * u_BC.length())) < pi / 2) {
        ans = distance(A, line(B, C));
    } else {
        ans = distance(A, B);
    }

    cout << setprecision(10) << fixed << ans << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}