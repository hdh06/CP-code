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

#define file "METRO"

int const N = 1e5 + 1;

struct edge{
    int v, w, id;
    edge(){}
    edge(int v, int w, int id): v(v), w(w), id(id){}
};

int n, m, s, t, k;
vector<edge> g[N];

namespace sub1{
    ll dis[N];
    bool minimize(ll &x, ll val){
        if (x == -1 || x > val){
            x = val;
            return true;
        }
        return false;
    }
    void solve(){
        memset(dis, -1, sizeof dis);
        dis[s] = 0;
        priority_queue<pair<ll, int> > que;
        que.push(mp(0, s));
        while (!que.empty()){
            int v = que.top().nd;
            que.pop();
            for (auto e: g[v]){
                ll w = e.w;
                if (v != s) w += e.id;
                if (minimize(dis[e.v], dis[v] + w))
                    que.push(mp(-dis[e.v], e.v));
            }
        }
        cout << dis[t] << "\n";
    }
}

namespace sub3{
    ll dis[N];
    bool minimize(ll &x, ll val){
        if (x == -1 || x > val){
            x = val;
            return true;
        }
        return false;
    }
    void solve(){
        memset(dis, -1, sizeof dis);
        dis[s] = 0;
        priority_queue<pair<ll, ii> > que;
        que.push(mp(0, mp(s, -1)));
        while (!que.empty()){
            int v = que.top().nd.st, p = que.top().nd.nd;
            ll d = que.top().st;
            que.pop();
            if (dis[v] != -d) continue;
            for (auto e: g[v]){
                ll w = e.w;
                if (p != -1) w += 1LL * p * k + e.id;
                if (minimize(dis[e.v], dis[v] + w))
                    que.push(mp(-dis[e.v], mp(e.v, e.id)));
            }
        }
        cout << dis[t] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin >> n >> m >> s >> t >> k;
    for (int i = 1; i <= m; i++){
        int a, b, w; cin >> a >> b >> w;
        g[a].pb(edge(b, w, i));
        // g[b].pb(edge(a, w, i));
    }

    sub3::solve();
    return 0;
}
