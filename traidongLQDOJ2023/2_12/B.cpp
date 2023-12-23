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

bool const SINGLE_TEST = 1;

int const INF = 1e9 + 5;
vi col, row;

int dx[] = {2, 1, -2, 1, 2, -1, -2, -1};
int dy[] = {1, 2, 1, -2, -1, 2, -1, -2};

int key(int x, int y){
	int k = lb(all(col), x) - col.begin();
	int d = lb(all(row), y) - row.begin();
	if (col[k + 1] - col[k] == 1)
	return k * row.size() + d;
}

bool isBan(int x, int y){
	if (*lb(all(col), x) == x) return true;
	if (*lb(all(row), y) == y) return true;
	return false;
}

bool check(int x, int y){
	int cnt = 0;
	for (int d = 0; d < 8; d++){
		int g = x + dx[d], h = y + dy[d];
		cnt += isBan(g, h);
	}
	return !!(8 - cnt);
}

int const N = 2e6 + 1;

int link[N];
int find(int v){return link[v] = link[v] == v? v: find(link[v]);}
bool unite(int a, int b){
	// debug(a, b);
	a = find(a), b = find(b);
	if (a == b) return false;
	link[a] = b;
	return true;
}

void solve(){	
	int n, q; cin >> n >> q;
	col.pb(-INF), col.pb(INF);
	row.pb(-INF), row.pb(INF);
	for (int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		col.pb(x);
		row.pb(y);
	}
	
	sort(all(col));
	sort(all(row));
	
	iota(link, link + N, 0);
	
	for (int i = 0; i < col.size() - 1; i++)
		for (int j = 0; j < row.size() - 1; j++){
			for (int x = col[i] + 1; x <= min(col[i] + 2, col[i + 1] - 1); x++)
				for (int y = row[j] + 1; y <= min(row[j] + 2, row[j + 1] - 1); y++)
					for (int d = 0; d < 8; d++){
						int g = x + dx[d], h = y + dy[d];
						if (isBan(g, h)) continue;
						unite(key(x, y), key(g, h));	
					}
			
			for (int x = col[i + 1] - 1; x >= max(col[i + 1] - 2, col[i] + 1); x--)
				for (int y = row[j] + 1; y <= min(row[j] + 2, row[j + 1] - 1); y++)
					for (int d = 0; d < 8; d++){
						int g = x + dx[d], h = y + dy[d];
						if (isBan(g, h)) continue;
						unite(key(x, y), key(g, h));
					}	
// 					
			for (int x = col[i] + 1; x <= min(col[i] + 2, col[i + 1] - 1); x++)
				for (int y = row[j + 1] - 1; y >= max(row[j + 1] - 2, row[j] + 1); y--)
					for (int d = 0; d < 8; d++){
						int g = x + dx[d], h = y + dy[d];
						if (isBan(g, h)) continue;
						unite(key(x, y), key(g, h));
					}
// 			
			for (int x = col[i + 1] - 1; x >= max(col[i + 1] - 2, col[i] + 1); x--)
				for (int y = row[j + 1] - 1; y >= max(row[j + 1] - 2, row[j] + 1); y--)
					for (int d = 0; d < 8; d++){
						int g = x + dx[d], h = y + dy[d];
						if (isBan(g, h)) continue;
						unite(key(x, y), key(g, h));
					}
			
		}
		
	while (q--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		// debug(key(a, b), key(c, d));
		if (a == c && b == d){
			cout << "1\n";
			continue;
		}
		if (!check(a, b) || !check(c, d) || isBan(a, b) || isBan(c, d)){
			cout << "0\n";
			continue;
		}
		
		
		if (find(key(a, b)) == find(key(c, d)))
			cout << "1\n";
		else cout << "0\n";
	}
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