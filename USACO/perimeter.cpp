// http://www.usaco.org/index.php?page=viewproblem2&cpid=895

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
#define file "perimeter"

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

int const dx[] = {0, 0, 1, -1};
int const dy[] = {1, -1, 0, 0};

int const N = 1001;

int n;
char arr[N][N];

int ccid[N][N], id = 0;

void DFS(int x, int y){
	if (x < 1 || y < 1 || x > n || y > n) return;
	if (arr[x][y] == '.') return;
	if (ccid[x][y]) return;
	ccid[x][y] = id;
	for (int d = 0; d < 4; d++)
		DFS(x + dx[d], y + dy[d]);
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (!ccid[i][j]){
			id++;
			DFS(i, j);	
		}
		
	vector<ii> aid(id + 1, ii(0, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (ccid[i][j] != 0){
			aid[ccid[i][j]].st++;
			for (int d = 0; d < 4; d++){
				int g = i + dx[d], h = j + dy[d];
				if (g < 1 || h < 1 || g > n || h > n || ccid[g][h] != ccid[i][j]) aid[ccid[i][j]].nd++;
			}
		}
	
	ii ans = {0, 0};
	for (auto x: aid){
		if (ans.st < x.st) ans = x;
		if (ans.st == x.st) ans.nd = min(ans.nd, x.nd);
	}
	
	cout << ans.st << " " << ans.nd << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef LOCAL
		cerr << "funnyline";
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