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

bool const SINGLE_TEST = 0;

int const N = 51;

int const dx[] = {0, 0, 1, -1};
int const dy[] = {1, -1, 0, 0};

int n, m;
char arr[N][N];

int timer = 0;
int vis[N][N];
void DFS(int x, int y){
	if (x < 1 || y < 1 || x > n || y > m) return;
	if (arr[x][y] == '#') return;
	if (vis[x][y] == timer) return;
	vis[x][y] = timer;
	for (int d = 0; d < 4; d++)
		DFS(x + dx[d], y + dy[d]);
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (arr[i][j] == 'B'){
			for (int d = 0; d < 4; d++){
				int g = i + dx[d], h = j + dy[d];
				if (g < 1 || h < 1 || g > n || h > m) continue;
				if (arr[g][h] == '.') arr[g][h] = '#';
			}
		}
		
	// for (int i = 1; i <= n; i++)
		// for (int j = 1; j <= m; j++)
			// cerr << arr[i][j] << " \n"[j == m];

		
	timer++;
	DFS(n, m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (arr[i][j] == 'B' && vis[i][j] == timer){
				cout << "No\n";
				return;
			}	
			if (arr[i][j] == 'G' && vis[i][j] != timer){
				cout << "No\n";
				return;
			}
		}
	cout << "Yes\n";
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