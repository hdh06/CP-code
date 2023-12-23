#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long ldb;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rd);}

#define file "HIGHWAY"

struct P{
    ll x, y;
    P(){}
    P(ll x, ll y):x(x), y(y){}
};

P vtc(P A, P B){
    return P(B.x - A.x, B.y - A.y);
}

ll cross(P A, P B){
    return A.x * B.y - A.y * B.x;
}

ll dot(P A, P B){
    return A.x * B.x + A.y * B.y;
}

int sign(ll x){
    if (x == 0) return 0;
    return (x < 0? -1: 1);
}

bool isEqual(P A, P B){return A.x == B.x && A.y == B.y;}

bool isIntersect(P A, P B, P C, P D){
//    if (isEqual(A, C) || isEqual(A, D) || isEqual(B, C) || isEqual(B, D)) return false;
    ll ABC = cross(vtc(A, B), vtc(A, C));
    ll ABD = cross(vtc(A, B), vtc(A, D));
    ll CDA = cross(vtc(C, D), vtc(C, A));
    ll CDB = cross(vtc(C, D), vtc(C, B));

    if (ABC == 0 || ABD == 0 || CDA == 0 || CDB == 0){
        if (ABC == 0 && dot(vtc(A, C), vtc(B, C)) < 0) return true;
        if (ABD == 0 && dot(vtc(A, D), vtc(B, D)) < 0) return true;
        if (CDA == 0 && dot(vtc(C, A), vtc(D, A)) < 0) return true;
        if (CDB == 0 && dot(vtc(C, B), vtc(D, B)) < 0) return true;
        return false;
    }
    return sign(ABC) * sign(ABD) < 0 && sign(CDA) * sign(CDB) < 0;
}

int const N = 7e5 + 1;

int nA, mA, nB, mB;
P A[N], B[N];
vii eA, eB;

namespace sub1{
    int pA[N], pB[N];
    void solve(){
        iota(pA + 1, pA + nA + 1, 1);
        iota(pB + 1, pB + nB + 1, 1);

        // shuffle(pA + 1, pA + nA + 1, rd);
        // shuffle(pB + 1, pB + nB + 1, rd);

        for (int i = 1; i <= nA; i++)
            for (int j = 1; j <= nB; j++){
                int x = pA[i], y = pB[j];
                bool fl = 1;
                for (auto e: eA) if (isIntersect(A[e.st], A[e.nd], A[x], B[y])){
                    fl = 0;
                    break;
                }
                for (auto e: eB) if (isIntersect(B[e.st], B[e.nd], A[x], B[y])){
                    fl = 0;
                    break;
                }
                if (fl){
                    cout << x << " " << y << "\n";
                    return;
                }
            }
        cout << 0 << "\n";
    }
}

void solve(){
    eA.clear(); eB.clear();
    cin >> nA >> mA;
    for (int i = 1; i <= nA; i++)
        cin >> A[i].x >> A[i].y;
    for (int i = 1; i <= mA; i++){
        int x, y; cin >> x >> y;
        eA.pb(mp(x, y));
    }

    cin >> nB >> mB;
    for (int i = 1; i <= nB; i++)
        cin >> B[i].x >> B[i].y;
    for (int i = 1; i <= mB; i++){
        int x, y; cin >> x >> y;
        eB.pb(mp(x, y));
    }

    sub1::solve();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
