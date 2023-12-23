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

int const N = 101;


ii p[N];

void solve(){
	int n, m, k; cin >> n >> m >> k;
	int x, y; cin >> x >> y;
	bool a = 0, b = 0;
	for (int i = 0; i < k; i++){
		int x, y; cin >> x >> y;
		if ((x + y) % 2 == 0) a = 1;
		else b = 1;
	}
	
	if ((x + y) % 2 == 0 && a){
		cout << "NO\n";
		return;
	}
	if ((x + y) % 2 != 0 && b){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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