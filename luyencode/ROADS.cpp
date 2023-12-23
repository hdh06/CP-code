#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;
typedef array<ll, 2> ii;

ll const N = 5001;

ii coords[N];
bool isGood[N][N] = {};

ll mu2(ll a){
    return a*a;
}

ll edu(ii a, ii b){
    return mu2(a[0] - b[0]) + mu2(a[1] - b[1]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);}
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        ll x, y; cin >> x >> y;
        coords[i] = {x, y};
    }

    for (int i = 1; i <= m; i++){
        ll x, y; cin >> x >> y;
        isGood[x][y] = true;
        isGood[y][x] = true;
    }

    priority_queue<ii> myque;
    myque.push({0, 1});

    bool vis[N] = {};

    db tong = (db)0;

    while (!myque.empty()){
        ll v = myque.top()[1];
        ll wv = -myque.top()[0];

        myque.pop();

        if (vis[v]) continue;
        vis[v] = true;
        tong += sqrt(wv); 

        ll w = LLONG_MAX, best = -1;

        for (ll i = 1; i <= n; i++) if (i != v && !vis[i]){
            w = min(w, edu(coords[v], coords[i]));
            if (isGood[v][i]) w = 0;
        }
        myque.push({-w, i});
    }

    cout << setprecision(2) << fixed << tong;
    return 0;
