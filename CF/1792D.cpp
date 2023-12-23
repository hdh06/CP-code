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

int const N = 1e5 + 1;

vi a[N], b[N];

void solve(){
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++){
		a[i].assign(m + 1, 0);
		b[i].assign(m + 1, 0);
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			b[i][a[i][j]] = j;
		}
	}
	
	sort(b + 1, b + n + 1);
	
	for (int i = 1; i <= n; i++){
		int z = lower_bound(b + 1, b + n + 1, a[i]) - b;
		
		int ans = 0;
		if (z > 1){
			int k = 1;
			while (k <= m && a[i][k] == b[z - 1][k]) k++;
			ans = max(ans, k - 1);
		}
		if (z <= n){
			int k = 1;
			while (k <= m && a[i][k] == b[z][k]) k++;
			ans = max(ans, k - 1);
		}
		cout << ans << " ";
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
}//it's coding time!