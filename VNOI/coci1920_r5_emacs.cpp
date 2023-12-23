#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 101;
int n, m;
char arr[N][N];
bool vis[N][N];

void DFS(int x, int y){
	if (x < 1 || x > n || y < 1 || y > m) return;
	if (arr[x][y] == '.') return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
	DFS(x + 1, y);
	DFS(x, y + 1);
}

void solve(){
 	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (arr[i][j] == '*' && !vis[i][j]) ans++;
			DFS(i, j);
		}
	}
	
	cout << ans;
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
}//it's coding time!