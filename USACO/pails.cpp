//http://www.usaco.org/index.php?page=viewproblem2&cpid=620

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
#define file "pails"

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

int const N = 101;

int X, Y, k, m;
int dis[N][N];

void solve(){	
	cin >> X >> Y >> k >> m;
	memset(dis, -1, sizeof dis);
	
	queue<iii> que;
	que.push({0, 0, 0});
	
	while (!que.empty()){
		int x = que.front()[0], y = que.front()[1], d = que.front()[2]; que.pop();
		
		if (dis[x][y] != -1) continue;
		if (d > k) continue;
		dis[x][y] = d;
		
		que.push({x, 0, d + 1});
		que.push({0, y, d + 1});
		
		que.push({X, y, d + 1});
		que.push({x, Y, d + 1});
		
		que.push({x + y - min(Y, x + y), min(Y, x + y), d + 1});
		que.push({min(X, x + y), x + y - min(X, x + y), d + 1});
	}
	
	int ans = m;
	for (int x = 0; x <= X; x++)
		for (int y = 0; y <= Y; y++)
			if (dis[x][y] != -1){
				debug(x, y);
				ans = min(ans, abs(m - x - y));
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