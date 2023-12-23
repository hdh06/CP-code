#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "flie"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

int const N = 205;
int const K = 1e4 + 1;

int n, m, k;
string a, b;
vii g[N];

bool cnt[K];
bool vis[N];

ii trace[N];

void DFS(int v){
	// if (vis[v]) return;
	vis[v] = true;
	
	for (auto u: g[v]) if (!vis[u.st]){
		trace[u.st] = mp(v, u.nd);
		DFS(u.st);
	}
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n >> m >> k;
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	
	for (int i = 1; i <= k; i++){
		int a, b; cin >> a >> b;
		g[a].pb({b + n, i});
		g[b + n].pb({a, i});
	}
	
	for (int i = 1; i <= n + m; i++){
		if (a[i] != b[i]){
			memset(vis, 0, sizeof vis);
			// memset(trace, 0, sizeof trace);
			DFS(i);
			int pos = -1;
			for (int j = i + 1; j <= n + m; j++)
				if (vis[j] && a[j] != b[j]){
					pos = j;
					break;
				}
			
			if (pos == -1){
				cout << "-1";
				return 0;
			}			
			
			a[i] = b[i];
			a[pos] = b[pos];
			while (pos != i){
				cnt[trace[pos].nd] ^= 1;
				pos = trace[pos].st;			
			}
		}
	}

	vi ans;
	for (int i = 1; i <= k; i++) if (cnt[i])
		ans.pb(i);
		
	cout << ans.size() << '\n';
	for (auto x: ans) cout << x << " ";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!