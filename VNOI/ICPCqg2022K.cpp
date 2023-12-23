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
typedef long double ldb;

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

bool const SINGLE_TEST = 1;

int const INF = 1e6;

void solve(){
	int n; cin >> n;
	
	vector<ii> z;
	for (int i = 1; i <= 3000; i++){
		for (int j = 1; j <= 3000; j++) if (gcd(i, j) == 1){
			int s = sqrt(i * i + j * j);
			if (s * s != i * i + j * j) continue;
			z.pb({i, j});
		}
	}
	
	sort(all(z), [](ii a, ii b){
		return (ldb) a.st / (ldb) a.nd < (ldb) b.st / (ldb) b.nd;
	});

	int x = -INF, y = -INF;
	cout << "YES\n-1000000 -1000000\n";
	int cnt = 0;
	for (int i = 2; i <= n - 1; i++){
		x += z[cnt].st;
		y += z[cnt].nd;
		cnt++;
		cout << x << " " << y << "\n";
	}
	cout << x << " " << -INF;
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