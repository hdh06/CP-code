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

int const N = 1e4 + 1;
int const INF = 1e7;

int n;
vi g[N];
string s;

int k = 0, id = 1;

void build(int v){
	int SiZe = s[k] - '0';
	k++;
	for (int i = 1; i <= SiZe; i++){
		id++;
		g[v].pb(id);
		build(id);
	}
}

ii dp[N][4];

ii DFS(int v, int c){
	ii &ans = dp[v][c];
	if (ans.st != -1) return ans;
	ans = mp(0, INF);
	if (g[v].size() == 1){
		for (int nc = 1; nc <= 3; nc++) if (nc != c){
			ii A = DFS(g[v][0], nc);
			ans.st = max(ans.st, A.st + (c == 1));
			ans.nd = min(ans.nd, A.nd + (c == 1));
		}
	}
	if (g[v].size() == 2){
		for (int a = 1; a <= 3; a++)
			for (int b = 1; b <= 3; b++) if (a != b && a != c && b != c){
				ii A = DFS(g[v][0], a), B = DFS(g[v][1], b);
				ans.st = max(ans.st, A.st + B.st + (c == 1));
				ans.nd = min(ans.nd, A.nd + B.nd + (c == 1));
			}
	}
	if (g[v].size() == 0)
		ans = mp(c == 1, c == 1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> s;
	n = s.size();
	build(1);
	
	// for (int i = 1; i <= n; i++)
		// debug(g[i]);
	
	memset(dp, -1, sizeof dp);
	
	ii ans = mp(0, INF);
	for (int i = 1; i <= 3; i++){
		ii A = DFS(1, i);
		ans.st = max(ans.st, A.st);
		ans.nd = min(ans.nd, A.nd);
	}
	
	cout << ans.st << " " << ans.nd << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!