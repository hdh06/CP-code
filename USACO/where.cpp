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
#define file "where"

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

int const N = 21;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int n;
char arr[N][N]; 

bool vis[N][N];

void DFS(int a, int b, int c, int d, char ch, int x, int y){
	
	if (x < a || y < b || c < x || d < y) return;
	if (arr[x][y] != ch) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;

	for (int dir = 0; dir < 4; dir++){
		DFS(a, b, c, d, ch, x + dx[dir], y + dy[dir]);
	}
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
			
	int ans = 0;
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			for (int c = a; c <= n; c++)
				for (int d = b; d <= n; d++){
					memset(vis, 0, sizeof vis);	
					int xA = a, yA = b, xB = -1, yB = -1;
					set<int> ms;
					for (int i = a; i <= c; i++)
						for (int j = b; j <= d; j++){
							ms.insert(arr[i][j]);
							if (arr[i][j] != arr[xA][yA]) xB = i, yB = j;
						}	
					
					if (ms.size() != 2) continue;
					DFS(a, b, c, d, arr[xA][yA], xA, yA);
					DFS(a, b, c, d, arr[xB][yB], xB, yB);
					
					bool flA = 1, flB = 1;
					for (int i = a; i <= c; i++)
						for (int j = b; j <= d; j++){
							if (arr[i][j] == arr[xA][yA] && !vis[i][j])	flA = 0;
							if (arr[i][j] == arr[xB][yB] && !vis[i][j])	flB = 0;
						}
					
					if (flA ^ flB){
						for (I)
					}
				}
				
		
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef LOCAL
		cerr << "USACO is fun haha\n";
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