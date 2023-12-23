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
	
	memset(vis, -1, sizeof vis);
	
	queue<Acut> que;
	for (int i = 2; i <= n; i++){
		que.push(Acut(i, 1, 1));
		que.push(Acut(i, m + 1, 3));
	}	
	for (int j = 2; j <= m; j++){
		que.push(Acut(1, j, 2));
		que.push(Acut(n + 1, j, 0));
	}
	
	int ans = 4 - 2 * (n + m) + 2;
	vis[1][1] = vis[1][m + 1] = vis[n + 1][1] = vis[n + 1][m + 1] = 4;
	// for (int i = 1; i <= n + 1; i++)
		// vis[i][1] = vis[i][m + 1] = 4;
	// for (int i = 1; i <= m + 1; i++)
		// vis[1][i] = vis[n + 1][i] = 4;
		
	while (!que.empty()){
		Acut c = que.front();
		// debug(c.x, c.y, c.d);
	
		que.pop();
		if (vis[c.x][c.y] != -1){
			if (vis[c.x][c.y] >= 4) continue;
			// debug(c.x, c.y);
			int d = (c.d + 2) % 4;
			for (int i = c.x, j = c.y; 1 <= i && i <= n + 1 && 1 <= j && j <= m + 1; i += dx[d], j += dy[d]){	
				que.push(Acut(i + dx[(d + 1) % 4], j + dy[(d + 1) % 4], (d + 1) % 4));
				que.push(Acut(i + dx[(d - 1 + 4)  % 4], j + dy[(d - 1 + 4)  % 4], (d - 1 + 4)  % 4));
				// if (i != c.x || j != c.y) vis[i][j] = -1;
			}
			d = (vis[c.x][c.y] + 2) % 4;
			for (int i = c.x, j = c.y; 1 <= i && i <= n + 1 && 1 <= j && j <= m + 1; i += dx[d], j += dy[d]){	
				que.push(Acut(i + dx[(d + 1) % 4], j + dy[(d + 1) % 4], (d + 1) % 4));
				que.push(Acut(i + dx[(d - 1 + 4)  % 4], j + dy[(d - 1 + 4)  % 4], (d - 1 + 4)  % 4));
				// vis[i][j] = -1;
			}
			continue;
		}
		vis[c.x][c.y] = c.d;
		ans++;
		
		int g = c.x + dx[c.d], h = c.y + dy[c.d];
		if (g < 1 || g > n + 1 || h < 1 || h > m + 1) continue;
		// debug(c.x, c.y, g, h, c.d);
		if (c.d == 0 || c.d == 2){
			int z = min(c.x, g);
			if (c.y == 1 || arr[z][c.y - 1] == arr[z][c.y]) continue;
		}
		if (c.d == 1 || c.d == 3){
			int z = min(c.y, h);
			// debug(z, c.x, (int)arr[c.x - 1][z], (int)arr[c.x][z]);
			if (c.x == 1 || arr[c.x - 1][z] == arr[c.x][z]) continue;
		}
		// debug(c.x, c.y, g, h, c.d);
		
		ans --;
		que.push(Acut(g, h, c.d)); 
	}
	
	
	for (int i = 1; i <= n + 1; i++){
		for (int j = 1; j <= m + 1; j++)
			if (vis[i][j] != -1) cerr << "*"; else cerr << ".";
		cerr << "\n";
	}
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