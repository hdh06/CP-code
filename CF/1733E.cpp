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

bool const SINGLE_TEST = 0;

int const N = 121;

ll a[N][N], b[N][N];

void solve(){
	ll t, x, y;
	cin >> t >> x >> y;
	
	if (t < x + y){
		cout << "NO\n";
		return;
	}
	
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	
	a[0][0] = t - x - y;
	b[0][0] = t - x - y + 1;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1; j++){
			a[i][j + 1] += a[i][j] - a[i][j] / 2;
			a[i + 1][j] += a[i][j] / 2;
			b[i][j + 1] += b[i][j] - b[i][j] / 2; 	
			b[i + 1][j] += b[i][j] / 2; 	
		}

	
	int g = -1;
	for (int i = 0; i < N - 1; i++) if (i <= x + y){
		if (a[i][x + y - i] != b[i][x + y - i])
			g = i;
	}
	debug(g, x + y - g);
	if (x == g && y == x + y - g){
		cout << "YES\n";
	}else cout << "NO\n";
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