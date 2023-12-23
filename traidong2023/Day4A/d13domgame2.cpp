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

int const N = 2005;

int const dx[] = {0, +1};
int const dy[] = {+1, 0};

int n, m;
char arr[N][N];

vi g[N];

int key[N][N];

int used[N], timer = 0;
int mtc[N];

int k;

bool visit(int v){
	if (used[v] == timer) return false;
	used[v] = timer;
	for (auto u: g[v]){
		if (mtc[u] == -1 || visit(mtc[u])){
			mtc[u] = v;
			return true;
		}
	}
	return false;
}

int vis[2 * N];

void DFS(int v){
	if (vis[v]) return;
	vis[v] = true;
	
	if (v <= k){
		DFS(mtc[v]);
		return;
	}
	for (auto u: g[v]) if (u != mtc[v]) 
		DFS(u);
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
			
	int id1 = 0, id2 = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) if (arr[i][j] != '#'){
			if ((i + j) % 2 == 0) key[i][j] = ++id1;
			else key[i][j] = ++id2;
		}
		
	}

	k = id1;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (arr[i][j] != '#')
			if ((i + j) % 2 != 0)
				key[i][j] += k;
	
	// debug(k);
	
	ll ans = 1LL * k * (k - 1);
	if (ans > 1000000){
		cout << 1000000;
		return 0;
	}
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (arr[i][j] != '#'){
			for (int d = 0; d < 2; d++){
				int gg = i + dx[d], h = j + dy[d];
				if (gg < 1 || gg > n || h < 1 || h > m || arr[gg][h] == '#') continue;
				g[key[i][j]].pb(key[gg][h]);
				g[key[gg][h]].pb(key[i][j]);
			}
		}
		
	// for (int i = 1; i <= n; i++)
		// for (int j = 1; j <= m; j++)
			// cerr << key[i][j] << " \n"[j == m];
	
	memset(mtc, -1, sizeof mtc);
	for (int i = 1; i <= k; i++){
		timer++;
		visit(i);
	}
	// for (int i = 1; i <= 2 * k; i++)
		// debug(g[i]);
	// for (int i = 1; i <= k; i++)

	
	for (int i = k + 1; i <= 2 * k; i++){
		mtc[mtc[i]] = i;
	}

	// debug(ans);

	for (int i = 1; i <= k; i++){
		memset(vis, 0, sizeof vis); 
		DFS(i);
		for (int j = k + 1; j <= 2 * k; j++) if (!vis[j]) ans++;
		ans = min(ans, 1000000LL);
	}
	
	// cerr << ans;
	
	cout << ans;
	// cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!