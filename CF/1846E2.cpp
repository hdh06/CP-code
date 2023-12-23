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

ll const N = 1e18 + 1;

set<ll> ms;
void init(){
	for (ll i = 2; i * i * i + i * i + i + 1 < N; i++){
		for (ll j = i * i * i + i * i + i + 1; j < N; j = j * i + 1){
			ms.insert(j);
			if (j > (N - 1) / i) break;
		}
	}
}
void solve(){
	ll n; cin >> n;
	if (ms.find(n) != ms.end()){
		cout << "YES\n";
		return;
	}
	
	ll z = sqrtl(n);
	if (z > 1 && z * z + z + 1 == n){
		cout << "YES\n";
		return;
	}
	
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	init();
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!