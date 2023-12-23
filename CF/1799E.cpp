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
int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};


int n, m;
char arr[N][N];
int vis[N][N];

void BFS(int i, int j, int id){
	queue<ii> que;
	que.push({i, j});
	vis[i][j] = id;
	
	while (!que.empty()){
		int i = que.front().st, j = que.front().nd; que.pop();
		
		for (int d = 0; d < 4; d++){
			int g = i + dx[d], h = j + dy[d];
			if (g < 1 || g > n || h < 1 || h > m) continue;
			if (vis[g][h] || arr[g][h] == '.') continue;
			
			vis[g][h] = id;
			que.push({g, h});
		}
	}
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
			
	for (int i = 1; i <= n; i++){
		int l = 1, r = m;
		while (l <= m && arr[i][l] == '.') l++;
		while (r >= 1 && arr[i][r] == '.') r--;
		
		for (int j = l; j <= r; j++) arr[i][j] = '#';
	}
	
	for (int j = 1; j <= m; j++){
		int l = 1, r = n;
		while (l <= n && arr[l][j] == '.') l++;
		while (r >= 1 && arr[r][j] == '.') r--;
		
		for (int i = l; i <= r; i++) arr[i][j] = '#';
	}
	
	memset(vis, 0, sizeof vis);
	
	int id = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (arr[i][j] == '#'){
			if (!vis[i][j]){
				id++;
				BFS(i, j, id);
			}
		}
	
	if (id == 2){
		int xl1 = n, xr1 = 1, yl1 = m, yr1 = 1;
		int xl2 = n, xr2 = 1, yl2 = m, yr2 = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if (vis[i][j] == 1)
					xl1 = min(xl1, i), xr1 = max(xr1, i), yl1 = min(yl1, j), yr1 = max(yr1, j);
				if (vis[i][j] == 2)
					xl2 = min(xl2, i), xr2 = max(xr2, i), yl2 = min(yl2, j), yr2 = max(yr2, j);
			}
		
		ii A, B;
		if (abs(xl1 - xr2) < abs(xl2 - xr1)) A.st = xl1, B.st = xr2;
		else A.st = xr1, B.st = xl2;
		if (abs(yr1 - yl2) < abs(yr2 - yl1)) A.nd = yr1, B.nd = yl2;
		else A.nd = yl1, B.nd = yr2;
		
		for (int i = min(A.st, B.st); i <= max(A.st, B.st); i++)
			arr[i][A.nd] = '#';
		for (int j = min(A.nd, B.nd); j <= max(A.nd, B.nd); j++)
			arr[max(A.st, B.st)][j] = '#';
			
	}
	
	for (int i = 1; i <= n; i++){
		int l = 1, r = m;
		while (l <= m && arr[i][l] == '.') l++;
		while (r >= 1 && arr[i][r] == '.') r--;
		
		for (int j = l; j <= r; j++) arr[i][j] = '#';
	}
	
	for (int j = 1; j <= m; j++){
		int l = 1, r = n;
		while (l <= n && arr[l][j] == '.') l++;
		while (r >= 1 && arr[r][j] == '.') r--;
		
		for (int i = l; i <= r; i++) arr[i][j] = '#';
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)	
			cout << arr[i][j];
		cout << "\n";
	}
	cout << "\n";
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