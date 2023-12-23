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

int const N = 2001;

int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};
// int const rv[] = {0, 3, 4, 1, 2};

int n, m;
char arr[N][N];

bool isCut[N][N][5];

// bool vis[N][N];
// 
// void DFS(int x, int y){
	// vis[x][y] = 1;
	// for (int d = 1; d <= 4; d++) if (!isCut[x][y][d]){
		// int g = x + dx[d], h = y + dy[d];
		// if (g < 1 || n < g || h < 1 || m < h || vis[g][h]) continue;
		// DFS(g, h);
	// }
// }
// 
struct Acut{
	int x, y, d;
	Acut(){}
	Acut(int x, int y, int d):x(x), y(y), d(d){}
}; // A cut begin from x y direction d = 1/2/3/4

int vis[N][N];

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
	
	//(1, 1) -> (n + 1, m + 1);
	
	for (int i = 1; i <= n; i++)
	
	// int ans = 0;
	// for (int i = 1; i <= n; i++)
		// for (int j = 1; j <= m; j++) if (!vis[i][j]){
			// ans++;
			// DFS(i, j);
		// }
// 			
	cout << ans << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!