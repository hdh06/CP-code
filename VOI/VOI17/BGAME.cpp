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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rd);}

#define file "BGAME"

int const N = 1e5 + 1;

struct edge{
    int a, b, w;
    edge(){}
    edge(int a, int b, int w):a(a), b(b), w(w){}
};

int n, m;
vector<edge> edl;

namespace sub1{
    int const N = 11;
    int lk[N], dg[N];
    int find(int v){return lk[v] = lk[v] == v? v: find(lk[v]);}

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return false;
        lk[a] = b;
        return true;
    }

    void solve(){
        sort(all(edl), [](edge a, edge b){
             return a.w > b.w;
        });

        for (auto &e: edl)
            e.a--, e.b--;
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++){
            iota(lk, lk + n, 0);
            fill(dg, dg + n, 0);
            int cnt = __builtin_popcount(mask);
            int maxx = 0;
            for (auto e: edl) if ((mask & (1 << e.a)) && (mask & (1 << e.b))){
                maxx = max(maxx, e.w);
                if (unite(e.a, e.b)) cnt--;
                dg[e.a]++;
                dg[e.b]++;
                if (cnt == 1){
                    int kkk = 0;
                    bool isOne = 0;
                    for (int i = 0; i < n; i++) if (mask & (1 << i)){
                        if (dg[i] & 1) kkk++;
                        if (dg[i] == 1) isOne = 1;
                    }
                    if (isOne) continue;
                    if (kkk % 2 == 0)
                        ans = max(ans, maxx + e.w);
                }
            }
        }
        cout << ans << "\n";
    }
}

namespace sub2{
    int const N = 1e5 + 5;
    int const L = 19;
    
    int lk[N], dg[N];
    int find(int v){return lk[v] = (lk[v] == v? v: find(lk[v]));}

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return false;
        lk[a] = b;
        return true;
    }
    
    bool isCse[N];
    vii g[N];
    
    int h[N], p[N][L], maxx[N][L];
    
	void DFS(int v){
		for (auto u: g[v]) if (u.st != p[v][0]){
			h[u.st] = h[v] + 1;
			p[u.st][0] = v;
			maxx[u.st][0] = u.nd;
			for (int i = 1; i < L; i++){
				p[u.st][i] = p[p[u.st][i - 1]][i - 1];
				maxx[u.st][i] = max(maxx[u.st][i - 1], maxx[p[u.st][i - 1]][i - 1]);
			}
			DFS(u.st);
		}
	}
	
	// int LCA(int a, int b){
		// if (h[a] > h[b]) swap(a, b);
		// int k = h[b] - h[a];
		// for (int i = 0; i < L; i++) if (k & (1 << i))
			// b = p[b][i];
		// if (a == b) return a;
		// for (int i = log2(h[a]); i >= 0; i--)
			// if (p[a][i] != p[b][i])
				// a = p[a][i], b = p[b][i];
		// return p[a][0];
	// }
	
	int get(int a, int b){
		int ans = 0;
		if (h[a] > h[b]) swap(a, b);
		int k = h[b] - h[a];
		for (int i = 0; i < L; i++) if (k & (1 << i))
			ans = max(ans, maxx[b][i]), b = p[b][i];
		if (a == b) return ans;
		for (int i = log2(h[a]); i >= 0; i--)
			if (p[a][i] != p[b][i]){
				ans = max(ans, maxx[a][i]);
				ans = max(ans, maxx[b][i]);
				a = p[a][i];
				b = p[b][i];
			}
		return max(ans, max(maxx[a][0], maxx[b][0]));
	}

    void solve(){
        sort(all(edl), [](edge a, edge b){
             return a.w > b.w;
        });
        
        iota(lk, lk + n + 1, 0);
        
		for (int i = 0; i < edl.size(); i++){
			edge e = edl[i];
       		if (unite(e.a, e.b)){
       			isCse[i] = 1;
       			g[e.a].pb(mp(e.b, e.w));
       			g[e.b].pb(mp(e.a, e.w));
       		}
       	} 
       	
		for (int i = 1; i <= n; i++) if (h[i] == 0) DFS(i);
       	
       	int ans = 0;
       	for (int i = 0; i < edl.size(); i++) if (!isCse[i])
       		ans = max(ans, get(edl[i].a, edl[i].b) + edl[i].w);
       	
		cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w; cin >> a >> b >> w;
        edl.pb(edge(a, b, w));
    }

	if (n <= 10)
 	   sub1::solve();
 	else 
 		sub2::solve();
    return 0;
}
/*
4 4
1 2 1
2 3 2
3 1 1
1 4 100

4 4
1 2 1
2 3 2
3 1 1
1 4 100

4 4
1 2 1
2 3 2
3 1 1
1 4 100
*/
