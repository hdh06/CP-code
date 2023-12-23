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
#define file "gates"

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

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int const N = 1005;

int n;
string s;

bool vis[2 * 2 * N][2 * 2 * N];

int maxX = 0, minX = 2 * 2 * N, maxY = 0, minY = 2 * 2 * N;

void DFS(int x, int y){
	if (x < minX || y < minY || x > maxX || y > maxY) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
	for (int d = 0; d < 4; d++)
		DFS(x + dx[d], y + dy[d]);
}

void solve(){	
	cin >> n >> s;
	int x = 0, y = 0;
	vis[x + 2 * n][y + 2 * n] = 1;

	for (auto c: s){
		if (c == 'N') x --;
		if (c == 'S') x ++;
		if (c == 'W') y --;
		if (c == 'E') y ++;
		vis[x + 2 * n][y + 2 * n] = 1;
		maxX = max(maxX, x + 2 * n);
		minX = min(minX, x + 2 * n);
		maxY = max(maxY, y + 2 * n);
		minY = min(minY, y + 2 * n);
		if (c == 'N') x --;
		if (c == 'S') x ++;
		if (c == 'W') y --;
		if (c == 'E') y ++;
		vis[x + 2 * n][y + 2 * n] = 1;
		maxX = max(maxX, x + 2 * n);
		minX = min(minX, x + 2 * n);
		maxY = max(maxY, y + 2 * n);
		minY = min(minY, y + 2 * n);
	}
	maxX++;
	minX--;
	maxY++;
	minY--;
	
	// int sz = 7;
	// for (int i = -sz; i <= sz; i++)
		// for (int j = -sz; j <= sz; j++)
			// cerr << vis[i + 2 * n][j + 2 * n] << " \n"[j == sz];
	
	int ans = 0;
	for (int i = minX; i <= maxX; i++)
		for (int j = minY; j <= maxY; j++) if (!vis[i][j]){
			ans++;
			
			DFS(i, j);
		}

	cout << ans - 1;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef LOCAL
		cerr << "funnyline\n";
	#else
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!