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
#define file "fiel"

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

bool const SINGLE_TEST = 1;

int const N = 1001;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int n, m;
char arr[N][N];

int dis[N][N];

bool minimize(int &x, int v){
	if (v == -1) return false;
	if (x == -1 || x > v){
		x = v;
		return true;
	}
	return false;
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
		
	deque<ii> que;	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == '-') que.pb(mp(i, j));
		
	for (int i = 1; i <= n; i++) que.pb(mp(i, 0)), que.pb(mp(i, m + 1));
	for (int i = 1; i <= m; i++) que.pb(mp(0, i)), que.pb(mp(n + 1, i));
	
	memset(dis, -1, sizeof dis);
	
	for (auto x: que) dis[x.st][x.nd] = 0;
	// debug(que);
	
	while (!que.empty()){
		int x = que.back().st, y = que.back().nd;
		que.pob();
		for (int d = 0; d < 4; d++){
			int g = x + dx[d], h = y + dy[d];
			if (g < 0 || g > n + 1 || h < 0 || h > m + 1 || dis[g][h] != -1) continue;
			// debug(x, y, g, h);
			if (minimize(dis[g][h], dis[x][y] + 1)) que.pf(mp(g, h));
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			ans = max(ans, dis[i][j]);
			// cerr << dis[i][j] << " \n"[j == m];
		}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!