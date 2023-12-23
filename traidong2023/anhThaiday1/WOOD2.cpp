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

int const dx[] = {0, -1, 0, 1, 0};
int const dy[] = {0, 0, 1, 0, -1};

int n, m;
char arr[N][N];

bool isCut[N][N][5];

bool vis[N][N];

void DFS(int x, int y){
	vis[x][y] = 1;
	for (int d = 1; d <= 4; d++) if (!isCut[x][y][d]){
		int g = x + dx[d], h = y + dy[d];
		if (g < 1 || n < g || h < 1 || m < h || vis[g][h]) continue;
		DFS(g, h);
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> n >> m;
	// if (n == 8 && m == 7){
		// cout << 7;
		// return 0;
	// }
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)	
			cin >> arr[i][j];
	
	for (int i = 1; i < n; i++){
		int j = 1;
		while (j <= m && arr[i][j] != arr[i + 1][j]){
			isCut[i][j][3] = isCut[i + 1][j][1] = 1;
			int k = i;
			while ()
			k = i + 1;
			j++;
		}
		j = m;
		while (j >= 1 && arr[i][j] != arr[i + 1][j]){
			isCut[i][j][3] = isCut[i + 1][j][1] = 1;
			j--;
		}
	}
	
	for (int j = 1; j < m; j++){
		int i = 1;
		while (i <= n && arr[i][j] != arr[i][j + 1]){
			isCut[i][j][2] = isCut[i][j + 1][4] = 1;
			i++;
		}
		i = n;
		while (i >= 1 && arr[i][j] != arr[i][j + 1]){
			isCut[i][j][2] = isCut[i][j + 1][4] = 1;
			i--;
		}
	}
	
	// debug(isCut[1][1][3]);
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (!vis[i][j]){
			ans++;
			DFS(i, j);
		}
			
	cout << ans << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!