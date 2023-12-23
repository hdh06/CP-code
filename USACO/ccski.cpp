// http://www.usaco.org/index.php?page=viewproblem2&cpid=380

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
#define file "ccski"

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

int const N = 501;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int n, m;
int arr[N][N];
bool isWP[N][N];

int timer = 0;
int vis[N][N];

void DFS(int x, int y, int k){
	if (vis[x][y] == timer) return;
	vis[x][y] = timer;
	for (int d = 0; d < 4; d++){
		int g = x + dx[d], h = y + dy[d];
		if (g < 1 || h < 1 || g > n || h > m) continue;
		if (abs(arr[g][h] - arr[x][y]) <= k)
			DFS(g, h, k);
	}
}

bool f(int x, int y, int k){
	timer++;
	DFS(x, y, k);
	
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			if (isWP[i][j] && vis[i][j] != timer)
				return false;
				
	return true;
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	
	int x = -1, y = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> isWP[i][j];
			if (isWP[i][j]) x = i,y = j;
		}
	
	if (x == -1){
		cout << 0;
		return;
	}
	
	int ans = -1;
	for (int l = 0, r = 1e9; l <= r;){
		int mid = l + (r - l) / 2;
		if (f(x, y, mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	cout << ans;
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